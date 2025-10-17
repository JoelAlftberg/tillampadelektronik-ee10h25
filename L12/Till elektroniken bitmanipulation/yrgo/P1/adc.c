/*
 * pot.c
 *
 * Created: 2023-08-11 14:21:56
 *  Author: mardea0831
 */ 
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "P1.h"

#define POT1 0
#define POT2 1
#define TEMPERATURE 2


void initiate_pots(void) {
    ADMUX = (1 << REFS0);
    ADCSRA = ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
    while ((ADCSRA & (1 << ADIF)) == 0) ;
    ADCSRA = (1 << ADIF);
    return;
}

uint16_t read_pot1() {
    ADMUX = ((1 << REFS0) | POT1);
    ADCSRA = ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
    while ((ADCSRA & (1 << ADIF)) == 0) ;
    ADCSRA = (1 << ADIF);
    return ADC;
}
uint16_t read_pot2() {
    ADMUX = ((1 << REFS0) | POT2);
    ADCSRA = ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
    while ((ADCSRA & (1 << ADIF)) == 0) ;
    ADCSRA = (1 << ADIF);
    return ADC;
}
uint16_t read_temperature() {
    ADMUX = ((1 << REFS0) | TEMPERATURE);
    ADCSRA = ((1 << ADEN) | (1 << ADSC) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
    while ((ADCSRA & (1 << ADIF)) == 0) ;
    ADCSRA = (1 << ADIF);
    /*
     ADC == 142 ~ 23.3 dgrC, 
     every ADC value is ~0,5 dgrC
     
     so return = 230 + ((142 - ADC)*5)
     
     return value is dgrC/10
    */
    
    return 233 + ((ADC - 142)*3);
    
}