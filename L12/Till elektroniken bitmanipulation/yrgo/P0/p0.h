/*
 * p0.h
 *
 * Created: 2023-08-21 13:56:06
 *  Author: mardea0831
 */ 

#ifndef FUNCTIONS_H_P0_

#define FUNCTIONS_H_P0_
#define F_CPU 16000000UL // 16 MHz klockfrekvens.
#include <stdint.h>
#include <stdbool.h>

void setup_p0(void);
void digital_out_2_on(void);
void digital_out_3_on(void);
void digital_out_4_on(void);
void digital_out_5_on(void);
void digital_out_6_on(void);
void digital_out_7_on(void);
void digital_out_8_on(void);
void digital_out_9_on(void);
void digital_out_10_on(void);
void digital_out_11_on(void);
void digital_out_12_on(void);
void digital_out_13_on(void);
void digital_out_2_off(void);
void digital_out_3_off(void);
void digital_out_4_off(void);
void digital_out_5_off(void);
void digital_out_6_off(void);
void digital_out_7_off(void);
void digital_out_8_off(void);
void digital_out_9_off(void);
void digital_out_10_off(void);
void digital_out_11_off(void);
void digital_out_12_off(void);
void digital_out_13_off(void);
void wait(uint16_t wait_ms);
void digital_out(uint8_t pin_number, bool output);
#endif /* FUNCTIONS_H_P0_ */