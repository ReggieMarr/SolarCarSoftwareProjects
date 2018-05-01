/* 
 * File:   lcd.h
 * Author: tsait
 *
 * Created on March 24, 2018, 12:24 AM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#define PIN_RS LATCbits.LATC7
#define PIN_RW LATCbits.LATC6
#define PIN_E LATCbits.LATC5

void delay_ms(unsigned int n);
void send_nibble(unsigned char nibble);
void send_command_byte(unsigned char byte);
void send_data_byte(unsigned char byte);
void config_lcd(void);
void write_to_lcd(const char* data);
void clear_lcd(void);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

