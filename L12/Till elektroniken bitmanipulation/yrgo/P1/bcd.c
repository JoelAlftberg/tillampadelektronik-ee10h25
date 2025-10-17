/*
 * bcd.c
 *
 * Created: 2023-08-30 11:59:29
 *  Author: mardea0831
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "P1.h"

void set_number(uint8_t number) {

    PORTD = number|(PORTD & 11110000);

}