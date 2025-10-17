/*
 * relay.c
 *
 * Created: 2023-08-30 14:48:34
 *  Author: mardea0831
 */ 
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "P1.h"

void relay(bool status){
    if(status) {
        PORTC |= (1 << 3);    
    } else {
        PORTC &= ~(1 << 3);
    }
}

bool is_relay_on(void){
    if(PORTC & (1 << 3)){
        return true;
    }
    else {
        return false;
    }
}

void relay_toggle(void) {
    if(is_relay_on()){
        relay(false);
    }
    else {
        relay(true);
    }
}