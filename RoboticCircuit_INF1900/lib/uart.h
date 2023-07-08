#ifndef UART_H
#define UART_H

#include "headers.h"

class UART
{
public:
    UART();
    void transmissionUART(uint8_t donnee);
    unsigned char receptionUART();
};
#endif