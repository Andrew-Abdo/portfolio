#ifndef MINUTERIE_H
#define MINUTERIE_H

#include "headers.h"

void startTimer0CTC(const uint8_t duration, const uint8_t PBx = PB2);
void stopTimer0CTC();
void partirMinuterie2CTC();
void arreterMinuterie2CTC();

#endif // MINUTERIE_H
