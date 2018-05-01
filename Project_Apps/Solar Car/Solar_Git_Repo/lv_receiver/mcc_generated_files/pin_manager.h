/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC18F26K80
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set HORN aliases
#define HORN_TRIS               TRISAbits.TRISA2
#define HORN_LAT                LATAbits.LATA2
#define HORN_PORT               PORTAbits.RA2
#define HORN_ANS                ANCON0bits.ANSEL2
#define HORN_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define HORN_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define HORN_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define HORN_GetValue()           PORTAbits.RA2
#define HORN_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define HORN_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define HORN_SetAnalogMode()  do { ANCON0bits.ANSEL2 = 1; } while(0)
#define HORN_SetDigitalMode() do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set FAN aliases
#define FAN_TRIS               TRISAbits.TRISA3
#define FAN_LAT                LATAbits.LATA3
#define FAN_PORT               PORTAbits.RA3
#define FAN_ANS                ANCON0bits.ANSEL3
#define FAN_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define FAN_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define FAN_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define FAN_GetValue()           PORTAbits.RA3
#define FAN_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define FAN_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define FAN_SetAnalogMode()  do { ANCON0bits.ANSEL3 = 1; } while(0)
#define FAN_SetDigitalMode() do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set LIGHTS_L aliases
#define LIGHTS_L_TRIS               TRISBbits.TRISB2
#define LIGHTS_L_LAT                LATBbits.LATB2
#define LIGHTS_L_PORT               PORTBbits.RB2
#define LIGHTS_L_WPU                WPUBbits.WPUB2
#define LIGHTS_L_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LIGHTS_L_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LIGHTS_L_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LIGHTS_L_GetValue()           PORTBbits.RB2
#define LIGHTS_L_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LIGHTS_L_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LIGHTS_L_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define LIGHTS_L_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)

// get/set LIGHTS_HAZARD aliases
#define LIGHTS_HAZARD_TRIS               TRISBbits.TRISB3
#define LIGHTS_HAZARD_LAT                LATBbits.LATB3
#define LIGHTS_HAZARD_PORT               PORTBbits.RB3
#define LIGHTS_HAZARD_WPU                WPUBbits.WPUB3
#define LIGHTS_HAZARD_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LIGHTS_HAZARD_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LIGHTS_HAZARD_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LIGHTS_HAZARD_GetValue()           PORTBbits.RB3
#define LIGHTS_HAZARD_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LIGHTS_HAZARD_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LIGHTS_HAZARD_SetPullup()      do { WPUBbits.WPUB3 = 1; } while(0)
#define LIGHTS_HAZARD_ResetPullup()    do { WPUBbits.WPUB3 = 0; } while(0)

// get/set LIGHTS_R aliases
#define LIGHTS_R_TRIS               TRISBbits.TRISB4
#define LIGHTS_R_LAT                LATBbits.LATB4
#define LIGHTS_R_PORT               PORTBbits.RB4
#define LIGHTS_R_WPU                WPUBbits.WPUB4
#define LIGHTS_R_ANS                ANCON1bits.ANSEL9
#define LIGHTS_R_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LIGHTS_R_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LIGHTS_R_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LIGHTS_R_GetValue()           PORTBbits.RB4
#define LIGHTS_R_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LIGHTS_R_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LIGHTS_R_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define LIGHTS_R_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define LIGHTS_R_SetAnalogMode()  do { ANCON1bits.ANSEL9 = 1; } while(0)
#define LIGHTS_R_SetDigitalMode() do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set LIGHTS_BRAKE aliases
#define LIGHTS_BRAKE_TRIS               TRISBbits.TRISB5
#define LIGHTS_BRAKE_LAT                LATBbits.LATB5
#define LIGHTS_BRAKE_PORT               PORTBbits.RB5
#define LIGHTS_BRAKE_WPU                WPUBbits.WPUB5
#define LIGHTS_BRAKE_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LIGHTS_BRAKE_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LIGHTS_BRAKE_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LIGHTS_BRAKE_GetValue()           PORTBbits.RB5
#define LIGHTS_BRAKE_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LIGHTS_BRAKE_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LIGHTS_BRAKE_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define LIGHTS_BRAKE_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)

// get/set RADIO aliases
#define RADIO_TRIS               TRISCbits.TRISC0
#define RADIO_LAT                LATCbits.LATC0
#define RADIO_PORT               PORTCbits.RC0
#define RADIO_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RADIO_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RADIO_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RADIO_GetValue()           PORTCbits.RC0
#define RADIO_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RADIO_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set DISPLAY aliases
#define DISPLAY_TRIS               TRISCbits.TRISC1
#define DISPLAY_LAT                LATCbits.LATC1
#define DISPLAY_PORT               PORTCbits.RC1
#define DISPLAY_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DISPLAY_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DISPLAY_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DISPLAY_GetValue()           PORTCbits.RC1
#define DISPLAY_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DISPLAY_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set TELEM aliases
#define TELEM_TRIS               TRISCbits.TRISC2
#define TELEM_LAT                LATCbits.LATC2
#define TELEM_PORT               PORTCbits.RC2
#define TELEM_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define TELEM_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define TELEM_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define TELEM_GetValue()           PORTCbits.RC2
#define TELEM_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define TELEM_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()    do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()   do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()   do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()         PORTCbits.RC4
#define RC4_SetDigitalInput()   do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()  do { TRISCbits.TRISC4 = 0; } while(0)

// get/set LIGHTS_HEAD aliases
#define LIGHTS_HEAD_TRIS               TRISCbits.TRISC5
#define LIGHTS_HEAD_LAT                LATCbits.LATC5
#define LIGHTS_HEAD_PORT               PORTCbits.RC5
#define LIGHTS_HEAD_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LIGHTS_HEAD_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LIGHTS_HEAD_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LIGHTS_HEAD_GetValue()           PORTCbits.RC5
#define LIGHTS_HEAD_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LIGHTS_HEAD_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/