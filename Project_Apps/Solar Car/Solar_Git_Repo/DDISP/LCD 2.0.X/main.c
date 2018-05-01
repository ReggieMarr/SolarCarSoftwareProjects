/*
 * File:   main.c
 * Author: tsait
 *
 * Created on March 23, 2018, 10:32 PM
 */


#include "config.h"
#include "lcd.h"

void main(void) {
    TRISC = 0b00000000; // Set RD0-7 as digital outputs
     
    // Let's just write to the LCD and never read!
    // We'll wait 2ms after every command since we can't
    // check the busy flag.
    PIN_RW = 0;
    PIN_RS = 0;
    PIN_E = 1;
      
    config_lcd();
    
    //strings must be 32 chars long, 16 chars on each line
    write_to_lcd(" wow lcd works  nice one!!      "); 
    
    while(1);
    return;
}
