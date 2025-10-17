/*
 * p0.c
 *
 * Created: 2023-08-21 13:55:49
 *  Author: mardea0831
 */ 


/*
* Function    in/out    software    arduino    328p
* Digital      out      PORTB 5     Pin 13     Pin 19
* Digital      out      PORTB 4     Pin 12     Pin 18
* Digital      out      PORTB 3     Pin 11     Pin 17
* Digital      out      PORTB 2     Pin 10     Pin 16
* Digital      out      PORTB 1     Pin 9      Pin 15
* Digital      out      PORTB 0     Pin 8      Pin 14
* Digital      out      PORTD 7     Pin 7      Pin 13
* Digital      out      PORTD 6     Pin 6      Pin 12
* Digital      out      PORTD 5     Pin 5      Pin 11
* Digital      out      PORTD 4     Pin 4      Pin 6
* Digital      out      PORTD 3     Pin 3      Pin 5
* Digital      out      PORTD 2     Pin 2      Pin 4
* Digital      out      PORTD 1     Pin 1      Pin 3
* Digital      out      PORTD 0     Pin 0      Pin 2
*/
#include "p0.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>

/*Using PORTD*/
#define DIGITAL_OUT_2 2
#define DIGITAL_OUT_3 3 
#define DIGITAL_OUT_4 4
#define DIGITAL_OUT_5 5
#define DIGITAL_OUT_6 6
#define DIGITAL_OUT_7 7

/*Using PORTB*/
#define DIGITAL_OUT_8  0
#define DIGITAL_OUT_9  1
#define DIGITAL_OUT_10  2
#define DIGITAL_OUT_11  3
#define DIGITAL_OUT_12  4
#define DIGITAL_OUT_13  5

void setup_p0(void) {
    DDRD = 255;
    DDRB = 255;
}    

/************************************************************************/
/* Function Name: wait(uint16_t ms)                                     */
/* parameter: int ms, milliseconds to wait                              */
/* Return: void                                                         */
/* Description:                                                         */
/* The program waits a amount of milliseconds                           */
/************************************************************************/
void wait(uint16_t wait_ms) {
    for (uint16_t i = 0;i<wait_ms;i++) {
        _delay_ms(1);
    }
}



/************************************************************************/
/* Function Name: digital_out_2_on .. digital_out_13_on                 */
/* parameter: void                                                      */
/* Return: void                                                         */
/* Description:                                                         */
/* Activates digital out 2 to 13 on the arduino board                   */
/************************************************************************/

void digital_out_2_on(void) {
    PORTD |= (1 << DIGITAL_OUT_2);
}
void digital_out_3_on(void) {
    PORTD |= (1 << DIGITAL_OUT_3);
}
void digital_out_4_on(void) {
    PORTD |= (1 << DIGITAL_OUT_4);
}
void digital_out_5_on(void) {
    PORTD |= (1 << DIGITAL_OUT_5);
}
void digital_out_6_on(void) {
    PORTD |= (1 << DIGITAL_OUT_6);
}
void digital_out_7_on(void) {
    PORTD |= (1 << DIGITAL_OUT_7);
}
void digital_out_8_on(void) {
    PORTB |= (1 << DIGITAL_OUT_8);
}
void digital_out_9_on(void) {
    PORTB |= (1 << DIGITAL_OUT_9);
}
void digital_out_10_on(void) {
    PORTB |= (1 << DIGITAL_OUT_10);
}
void digital_out_11_on(void) {
    PORTB |= (1 << DIGITAL_OUT_11);
}
void digital_out_12_on(void) {
    PORTB |= (1 << DIGITAL_OUT_12);
}
void digital_out_13_on(void) {
    PORTB |= (1 << DIGITAL_OUT_13);
}


/************************************************************************/
/* Function Name: digital_out_2_off .. digital_out_13_off               */
/* parameter: void                                                      */
/* Return: void                                                         */
/* Description:                                                         */
/* Turn off digital out 2 to 13 on the arduino board                    */
/************************************************************************/

void digital_out_2_off(void) {
    PORTD &= ~(1 << DIGITAL_OUT_2);
}
void digital_out_3_off(void) {
    PORTD &= ~(1 << DIGITAL_OUT_3);
}
void digital_out_4_off(void) {
    PORTD &= ~(1 << DIGITAL_OUT_4);
}
void digital_out_5_off(void) {
    PORTD &= ~(1 << DIGITAL_OUT_5);
}
void digital_out_6_off(void) {
    PORTD &= ~(1 << DIGITAL_OUT_6);
}
void digital_out_7_off(void) {
    PORTD &= ~(1 << DIGITAL_OUT_7);
}
void digital_out_8_off(void) {
    PORTB &= ~(1 << DIGITAL_OUT_8);
}
void digital_out_9_off(void) {
    PORTB &= ~(1 << DIGITAL_OUT_9);
}
void digital_out_10_off(void) {
    PORTB &= ~(1 << DIGITAL_OUT_10);
}
void digital_out_11_off(void) {
    PORTB &= ~(1 << DIGITAL_OUT_11);
}
void digital_out_12_off(void) {
    PORTB &= ~(1 << DIGITAL_OUT_12);
}
void digital_out_13_off(void) {
    PORTB &= ~(1 << DIGITAL_OUT_13);
}


/************************************************************************/
/* Function Name: digital_out                                           */
/* parameter: uint8_t pin_number, bool output                           */
/* Return: void                                                         */
/* Description:                                                         */
/* pin_number is the pin that shall be affected (2 - 13)                */
/* if pin_number is under 2 or above 13, then all pins 2 - 13 is        */
/* affected                                                             */
/* output is true for output, false for no output                       */
/************************************************************************/
void digital_out(uint8_t pin_number, bool output) {

    if(pin_number > 1 && pin_number < 8) {
        /*PORTD*/
        if (output) {
            PORTD |= (1 << pin_number);            
        } else {
            PORTD &= ~(1 << pin_number);           
        }
    } else if((pin_number > 7) && (pin_number < 14)) {
        /*PORTB*/
        if (output) {
            PORTB |= (1 << (pin_number - 8));
        } else {
            PORTB &= ~(1 << (pin_number - 8));
        }
    } else {
        /*pin_number above 13 affects all outputs*/
        if (output) {
            PORTB |= 0b00111111;
            PORTD |= 0b11111100;  
            } else {
            PORTB &= ~(0b00111111);
            PORTD &= ~(0b11111100);
            
        }        
    }  
}