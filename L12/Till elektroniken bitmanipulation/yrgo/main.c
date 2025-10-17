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
    Programmet l�ser av POT1 och delar upp det i 8 delar och visar sedan resultatet via bin�rkod
    p� LED 1,2 och 3 enligt tabellen nedan
    
    V�rde   Bin�rt  POT-V�rde
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
        /*L�ser av och skalar ner pot-v�rdet s� vi f�r ett v�rde mellan 0 - 7*/
        pot_value = read_pot1()/128;
        
        /*H�r anv�nds bitmanipulation f�r att "plocka ut" de tre olika bitarna som skall
        t�nda/sl�cka aktuell led f�r att visa det bin�ra talet*/
        led(3,(pot_value & 0b00000001));
        led(2,(pot_value & 0b00000010));
        led(1,(pot_value & 0b00000100));
    }
}