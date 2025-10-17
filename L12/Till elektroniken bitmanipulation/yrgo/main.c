#include <avr/io.h>


/*Include the correct header file */
#include "p0/P0.h"
#include "p1/P1.h"
#include <time.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    setup_p1();
    
        /*
    Programmet läser av POT1 och delar upp det i 8 delar och visar sedan resultatet via binärkod
    på LED 1,2 och 3 enligt tabellen nedan
    
    Värde   Binärt  POT-Värde
    -------------------------
    0       000       0 - 127
    1       001     128 - 255
    2       010     256 - 383
    3       011     384 - 511
    4       100     512 - 639
    5       101     640 - 767
    6       110     768 - 895
    7       111     896 - 1023
    */
        uint8_t pot_value = 0;
    while(1) {
        /*Läser av och skalar ner pot-värdet så vi får ett värde mellan 0 - 7*/
        pot_value = read_pot1()/128;
        
        /*Här används bitmanipulation för att "plocka ut" de tre olika bitarna som skall
        tända/släcka aktuell led för att visa det binära talet*/
        led(3,(pot_value & 0b00000001));
        led(2,(pot_value & 0b00000010));
        led(1,(pot_value & 0b00000100));
    }
}