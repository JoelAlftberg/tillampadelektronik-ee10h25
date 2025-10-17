/*
* functions.c
*
* Created: 2023-08-10 11:53:53
*  Author: mardea0831
*/
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "P1.h"
/*
* Function    in/out    software    arduino    328p
* red led     out       PORTB 1     Pin 9      Pin 15
* green led   out       PORTD 6     Pin 6      Pin 12
* blue led    out       PORTD 5     Pin 5      Pin 11
*
*
*
*/
#define LED1 1
#define LED2 6
#define LED3 5

void led(uint8_t led_number, bool status) {
    if (status){
        if(led_number == 1) {
            led1(true);
        }else if (led_number == 2) {
            led2(true);
        }else if (led_number == 3) {
            led3(true);
        }else {
            led1(true);
            led2(true);
            led3(true);
        }
    } else {
        if(led_number == 1) {
            led1(false);
        }else if (led_number == 2) {
            led2(false);
        }else if (led_number == 3) {
            led3(false);
        }else {
            led1(false);
            led2(false);
            led3(false);
        }
    }
}


void led1(bool active) {
    if (active) {
        PORTB |= (1 << LED1);
    }else {
        PORTB &= ~(1 << LED1);    
    }
}
bool is_led1_on(void){
    if(PORTB & (1 << LED1)){
        return true;
    }
    else {
        return false;
    }
}

void led1_toggle(void) {
    if(is_led1_on()){
        led1(false);
    }
    else {
        led1(true);
    }

}

void led2(bool active) {
    if(active) {
        PORTD |= (1 << LED2);    
    } else {
        PORTD &= ~(1 << LED2);    
    }
}

bool is_led2_on(void){
    if(PORTD & (1 << LED2)){
        return true;
    }
    else {
        return false;
    }
}

void led2_toggle(void) {
    if(is_led2_on()){
        led2(false);
    }
    else {
        led2(true);
    }
}

void led3(bool active) {
    if (active) {
        PORTD |= (1 << LED3);    
    } else {
        PORTD &= ~(1 << LED3);        
    }
}

bool is_led3_on(void){
    if(PORTD & (1 << LED3)){
        return true;
    }
    else {
        return false;
    }
}

void led3_toggle(void) {
    if(is_led3_on()){
        led3(false);
    }
    else {
        led3(true);
    }

}
