#include "commun.h"

namespace commun{
    void delai_ms(const uint16_t duree_ms = 1000){
        for(uint16_t i = 0; i < duree_ms; i++)
            _delay_ms(1);
    }

    void delai_us(const uint16_t duree_us = 10){
        for(uint16_t i = 0; i < duree_us; i++)
            _delay_us(1);
    }
} // namespace commun