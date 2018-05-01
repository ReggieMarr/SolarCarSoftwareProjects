/*
 * File:   lcd.c
 * Author: tsait
 *
 * Created on March 24, 2018, 12:24 AM
 */


#include <xc.h>
#include "lcd.h"

void delay_ms(unsigned int n)
{
    while(n--) { 
        _delay(4000);
    }
}

void send_nibble(unsigned char nibble)
{
    // Set RC0-3 without affecting RC4-7
    LATC = (LATC & 0xF0) + nibble;
    delay_ms(1);
    // Note: data is latched on falling edge of pin E
    PIN_E = 0;
    delay_ms(1);
    PIN_E = 1;
    delay_ms(2); // Enough time even for slowest command
}
  
// Send a command byte (i.e. with pin RS low)
void send_command_byte(unsigned char byte)
{
    PIN_RS = 0;
    send_nibble(byte >> 4);
    send_nibble(byte & 0xF);
}
  
// Send a data byte (i.e. with pin RS high)
void send_data_byte(unsigned char byte)
{
    PIN_RS = 1;
    send_nibble(byte >> 4);
    send_nibble(byte & 0xF);
}

void config_lcd(void) {
    // We'll wait 2ms after every command since we can't
    // check the busy flag.
    
    // Some LCD modules require a delay after power-up
    // before you can begin communicating with them, so
    // I'm putting a 1 second delay here just in case.
    delay_ms(1000);
    
    delay_ms(16); // must be more than 15ms
    send_nibble(0b0011);
    delay_ms(5); // must be more than 4.1ms
    send_nibble(0b0011);
    delay_ms(1); // must be more than 100us
    send_nibble(0b0011);
    delay_ms(5); // must be more than 4.1ms
    send_nibble(0b0010); // select 4-bit mode
    
    // Display settings
    send_command_byte(0b00101000); // N=0 : 2 lines (half lines!), F=0 : 5x7 font
    send_command_byte(0b00001000); // Display: display off, cursor off, blink off
    send_command_byte(0b00000001); // Clear display
    send_command_byte(0b00000110); // Set entry mode: ID=1, S=0
    send_command_byte(0b00001101); // Display: display on, cursor off, blink on
}

void write_to_lcd(const char* data) {
    send_command_byte(0x02); // Go to start of line 1
    for (int n=0 ; n<16 ; ++n) {
        send_data_byte(data[n]);
    }
    send_command_byte(0xC0); // Go to start of line 2
    for (int n=16 ; n<32 ; ++n) {
        send_data_byte(data[n]);
    }
}

void clear_lcd(void) {
    send_command_byte(0b00000001);
}