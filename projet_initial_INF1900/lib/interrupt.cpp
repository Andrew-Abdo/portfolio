#include "interrupt.h"

  //TODO
Interrupt::Interrupt(uint8_t id, TYPE_CONTROLE type)
{
    
    // unsigned char sreg; // je le met en commentaire juste pour faire des tests fonctionnel
    /* Save global interrupt flag */
    // sreg = SREG; //Si on sauve SREG avant denable les interruption les bits de SREG seront a 0, apres pourquoi on le restore si les bits de SREG doivent changer a 1.
    cli();
    initINTX(id);
    initEICRA(type);
    // SREG = sreg; //Aymeric, tu pourras me reexpliquer comment SREG fonctionne, pcq si store SREG avant denable les interruptions et quon le pop back, les interruptions ne seront pas enabled si jai bien compris
    sei();
};

// Cette fonction doit etre utilisée dans une routine d'interruption, on assume qu'un délai de debounce est traité dans la routine.
// Il n'est donc pas nécessaire d'ajouter de debounce explicite ici.
bool Interrupt::isButtonPressed(){   
    return (*PINX & _BV(PX));
};

void Interrupt::initINTX(uint8_t id){
    switch (id){
    case 0:
        PX = PD2;
        PINX = &PIND;
        //Mettre les pins en consequence a 0 (entree)
        DDRD &= ~_BV(PX);
        ISCn0 = ISC00;
        ISCn1 = ISC01;
        EIMSK |= _BV(INT0);
        break;

    case 1:
        PX = PD3;
        PINX = &PIND;
        DDRD &= ~(_BV(PX));
        ISCn0 = ISC10;
        ISCn1 = ISC11;
        EIMSK |= _BV(INT1);
        break;
    case 2:
        PX = PB2;
        PINX = &PINB;
        DDRB &= ~(_BV(PX));
        ISCn0 = ISC20;
        ISCn1 = ISC21;
        EIMSK |= _BV(INT2);
        break;
    }
};

void Interrupt::initEICRA(TYPE_CONTROLE type){
    switch (type){
    case LOW_LEVEL:
        EICRA = 0;
        break;
    case ANY_EDGE:
        EICRA |= _BV(ISCn0);
        break;
    case FALLING_EDGE:
        EICRA |= _BV(ISCn1);
        break;
    case RISING_EDGE:
        EICRA |= _BV(ISCn0);
        EICRA |= _BV(ISCn1);
        break;
    }
};