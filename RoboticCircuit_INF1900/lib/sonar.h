/*
 * Ce code permet d'utiliser le Sonar ultra sonic SRF05, par défaut nous le connectons sur le PORTA au pin PA0 et PA1;
*/
// TODO
#ifndef SONAR_H
#define SONAR_H

#include "headers.h"
#include "commun.h"


const int accuracy = 4;   // Incertitude associee au sonar en cm
const int maximum_effective_range = 517; // Distance maximale que le sonar peut trouver en cm.


class Sonar {
    public:
        Sonar();
        void envoyerSignal();
        void ecouterEcho();
        uint16_t wavelength;
        uint16_t pulse_width;
        int distance;
};
#endif
