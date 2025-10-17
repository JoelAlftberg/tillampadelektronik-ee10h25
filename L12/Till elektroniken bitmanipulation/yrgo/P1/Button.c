/*
 * Button.c
 *
 * Created: 2023-08-11 10:34:46
 *  Author: mardea0831
 */ 
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "P1.h"

/*
* Function    in/out    software    arduino    328p
* button 1     out       PORTB 5     Pin 13     Pin 19
* button 2     out       PORTB 4     Pin 12     Pin 18
* button 3     out       PORTB 3     Pin 11     Pin 17
*/
#define BUTTON1 0
#define BUTTON2 7
#define BUTTON3 4

bool sw1(void) {
    if (PINB & (1 << BUTTON1)) {
        return true;
    }else {
        return false;
    }
}
bool sw2(void) {
    if (PIND & (1 << BUTTON2)) {
        return true;
        }else {
        return false;
    }
}
bool sw3(void) {
    if (PIND & (1 << BUTTON3)) {
        return true;
        }else {
        return false;
    }
}