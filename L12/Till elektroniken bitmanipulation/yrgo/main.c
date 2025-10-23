#include <avr/io.h>


/*Include the correct header file */
#include "p0/P0.h"
#include "p1/P1.h"
#include <time.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

// display_buffer[0] = integer, display_buffer[1] = decimal, display_buffer[2] = decimal_point;
uint16_t display_buffer[3] = {};
        
int main(void)
{
    setup_p0();
    
   /* 
   if d7 high -> Rset = 330 else if d8 -> high Rset = 33000
   
   Read from A0 - 16 samples with for loop (hope for some noise)
   average = divide A0 by 16
   voltage_read = average value * (5.0f / 1023.0f)
   R_measured = (voltage_read * R_set) / (5 - voltage_read);
   
   */
               
    while(1){
        
    }
        
        
        // if power just turned on, do some kind of starting sequence (init)
        // check the mode we are in
            // if mode has changed since last loop, display mode (ex U1 for low voltage, U2 for high voltage)
        
        // depending on mode, do appropriate math
        // handle number output by rounding and formatting
        // display number

}

/*

Takes a 3 digit decimal part number as input and then rounds it up to the nearest hundreth which for
a 3 digit number is it's nearest ten. It then returns two digit to represent the hundreds part.
Example, number = 789 (0.789) round to nearest hundreth so  789 -> 790 (0.790) then /= 10 so it becomes 79

*/
uint16_t round_to_hundreth(uint16_t decimal_part){
    // number = 789 (0.789) round to nearest tenth so  789 -> 790 (0.790) then /= 10 so it becomes 79
    uint8_t remainder = decimal_part % 10;
    if (remainder > 5){
        decimal_part += (10 - remainder);
    }
    else if (remainder < 5 && remainder != 0){
        decimal_part -= remainder;
    }
    
    return (decimal_part / 10);
}

/*

Takes a 3 digit decimal part number as input and then rounds it up to the nearest tenth which for
a 3 digit number is it's nearest hundred. It then returns a single digit to represent the tenth part.
Example, number = 789 (0.789) round to nearest tenth so  789 -> 800 (0.800) then /= 100 so it becomes 8

*/
uint16_t round_to_tenth(uint16_t decimal_part){

    uint8_t remainder = decimal_part % 100;
    if (remainder > 50){
        decimal_part += (100 - remainder);
    }
    else if (remainder < 50 && remainder != 0){
        decimal_part -= remainder;
    }
    
    return (decimal_part / 100);
}

/*

Takes a positive float as an input (value between 0 - 100000) and updates the display_buffer[]
array with the value rounded and converted to a suitable format for a 3-digit display

*/
void display_buffer_update(float number){
    
    uint16_t num_decimal_part = 0;

    if (number < 0){
        // {404, 404, 3} in display buffer will evaluate to ERR
        display_buffer[0] = 404;
        display_buffer[1] = 404;
        display_buffer[2] = 3;
        return;
    }
    // 1k to 99.9k range
    if (number > 1000 && number < 100000){

        uint8_t num_thousands = number /= 1000;
        num_decimal_part = number - (num_thousands * 1000);
        display_buffer[0] = num_thousands;
        
        if (num_thousands < 10){
            // example 7825 -> num_decimal = 825 (0.825), round to nearest hundreth 830 (0.830) and then do /= 10 so it becomes 83
            
            display_buffer[1] = round_to_hundreth(num_decimal_part);
            display_buffer[2] = 1;         
        }
        else if (num_thousands > 10){
            // example 24789 -> num_decimal = 789 (0.789) round to nearest tenth so  789 -> 800 (0.800) then /= 100 so it becomes 8
            display_buffer[1] = round_to_tenth(num_decimal_part);
            display_buffer[2] = 2;
        }
    }
    // 0 to 999 range 
    else if (number > 0 && number < 1000){
        
        uint16_t num_integer_part = (uint16_t) number;
        num_decimal_part = (number - num_integer_part) * 1000;

        // example 6.789123   
        if (number < 10 && number > 0){
            display_buffer[1] = round_to_hundreth(num_decimal_part);
            display_buffer[2] = 1;  
        }
        // example 48.14722
        else if (number > 10 && number < 100){
            display_buffer[1] = round_to_tenth(num_decimal_part);
            display_buffer[2] = 1;
        }
        // example 453.51452
        else if (number > 10 && number < 1000){
            
            if (num_decimal_part > 500){
                num_integer_part++;
            }
            
            display_buffer[1] = 0;
            display_buffer[2] = 3;
            
        }
        
        display_buffer[0] = num_integer_part;
        
    }              
}

/*

Send the data present in the buffer to the 3 digit 7-segment display
Use the HAL functions for outputting digits found in the drivers.c file

TODO: write drivers first for sending a number to a specific digit ex.
display_digit(uint8_t number, uint8_t digit, uint8_t decimal_point);
display_codes(uint8_t mode);

*/
void display_buffer_send(void){
    
}