/*
 * functions.h
 *
 * Created: 2023-08-10 13:09:26
 *  Author: mardea0831
 */ 


#ifndef FUNCTIONS_H_P1_
#define FUNCTIONS_H_P1_
#define F_CPU 16000000UL // 16 MHz klockfrekvens.

#include <stdbool.h>
#include <stdint.h>


void setup_p1(void);

/*LED-funktioner*/
void led1(bool active);
void led2(bool active);
void led3(bool active);
void led1_toggle(void);
void led2_toggle(void);
void led3_toggle(void);
bool is_led1_on(void);
bool is_led2_on(void);
bool is_led3_on(void);
void led(uint8_t led_number, bool status);

/*switch-funktioner*/
bool sw1(void);
bool sw2(void);
bool sw3(void);


/*Analoga ingångar*/
uint16_t read_pot1(void);
uint16_t read_pot2(void);
uint16_t read_temperature(void);


/*7-segments display*/    
void set_number(uint8_t number);    

/*Relay-funktioner*/
void relay(bool status);
bool is_relay_on(void);
void relay_toggle(void);
#endif /* FUNCTIONS_H_P1_ */