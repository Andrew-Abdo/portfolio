#include "display.h"

Display::Display(){
    port_ = &PORTC;
    ddr_ = &DDRC;
    lcmd_init_4bit(&DDRC, &PORTC);
}

Display::Display(volatile uint8_t* ddr, volatile uint8_t*  port){
    port_ = port;
    ddr_ = ddr;
    lcmd_init_4bit(ddr, port);
}

/*
 * Prend une chaine de caractere en parametre et l'ecrit sur le display LCD
 * @param data : chaine de caractere
 */
void Display::ecrire(const char* data){
    effacerAffichage();
    uint16_t n = strlen(data);
    for(uint16_t i = 0; i < n; i++)
        lcmd_write(data[i], port_);
}

void Display::effacerAffichage(){
    lcmd_disp_clear(port_);
}