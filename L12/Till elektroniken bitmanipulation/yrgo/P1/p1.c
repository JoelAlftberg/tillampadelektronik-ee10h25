/*
 * p1.c
 *
 * Created: 2023-08-30 11:34:50
 *  Author: mardea0831
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
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
#define BUTTON1 0
#define BUTTON2 7
#define BUTTON3 4

/************************************************************************/
/* initiating the i/o pins for the correct function                     */
/*                                                                      */
/************************************************************************/

void setup_p1(void) {

    /*Sets PINs for PORTB as outputs*/
    DDRB = (1 << LED1);
    
    /*Sets PINs for PORTC as outputs*/
    DDRC = (1 << 3);
    
    /*Sets PINs for PORTD as outputs*/
    DDRD &= ~(1 << BUTTON2);
    DDRD &= ~(1 << BUTTON3);
    DDRD = 0b001101111;
    
    /*Turns off the numeric display*/
    PORTD |= 0b00001111;

}