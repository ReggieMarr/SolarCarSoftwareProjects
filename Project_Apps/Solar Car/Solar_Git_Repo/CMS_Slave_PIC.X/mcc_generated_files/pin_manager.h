/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F26K80
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
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

// get/set digitalOUT aliases
#define digitalOUT_TRIS                 TRISBbits.TRISB0
#define digitalOUT_LAT                  LATBbits.LATB0
#define digitalOUT_PORT                 PORTBbits.RB0
#define digitalOUT_WPU                  WPUBbits.WPUB0
#define digitalOUT_ANS                  ANCON1bits.ANSEL10
#define digitalOUT_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define digitalOUT_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define digitalOUT_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define digitalOUT_GetValue()           PORTBbits.RB0
#define digitalOUT_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define digitalOUT_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define digitalOUT_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define digitalOUT_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define digitalOUT_SetAnalogMode()      do { ANCON1bits.ANSEL10 = 1; } while(0)
#define digitalOUT_SetDigitalMode()     do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set digitalIN aliases
#define digitalIN_TRIS                 TRISBbits.TRISB1
#define digitalIN_LAT                  LATBbits.LATB1
#define digitalIN_PORT                 PORTBbits.RB1
#define digitalIN_WPU                  WPUBbits.WPUB1
#define digitalIN_ANS                  ANCON1bits.ANSEL8
#define digitalIN_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define digitalIN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define digitalIN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define digitalIN_GetValue()           PORTBbits.RB1
#define digitalIN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define digitalIN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define digitalIN_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define digitalIN_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define digitalIN_SetAnalogMode()      do { ANCON1bits.ANSEL8 = 1; } while(0)
#define digitalIN_SetDigitalMode()     do { ANCON1bits.ANSEL8 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()               do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()                do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()                do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()       do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()      do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()               do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()                do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()                do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()       do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()      do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)

// get/set I2C_Status aliases
#define I2C_Status_TRIS                 TRISBbits.TRISB4
#define I2C_Status_LAT                  LATBbits.LATB4
#define I2C_Status_PORT                 PORTBbits.RB4
#define I2C_Status_WPU                  WPUBbits.WPUB4
#define I2C_Status_ANS                  ANCON1bits.ANSEL9
#define I2C_Status_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define I2C_Status_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define I2C_Status_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define I2C_Status_GetValue()           PORTBbits.RB4
#define I2C_Status_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define I2C_Status_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define I2C_Status_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define I2C_Status_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define I2C_Status_SetAnalogMode()      do { ANCON1bits.ANSEL9 = 1; } while(0)
#define I2C_Status_SetDigitalMode()     do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()               do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()                do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()                do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()       do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()      do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()               do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()                do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()                do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()       do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()      do { TRISCbits.TRISC2 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS                 TRISCbits.TRISC3
#define SCL_LAT                  LATCbits.LATC3
#define SCL_PORT                 PORTCbits.RC3
#define SCL_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL_GetValue()           PORTCbits.RC3
#define SCL_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS                 TRISCbits.TRISC4
#define SDA_LAT                  LATCbits.LATC4
#define SDA_PORT                 PORTCbits.RC4
#define SDA_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA_GetValue()           PORTCbits.RC4
#define SDA_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()               do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()                do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()                do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()       do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()      do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()               do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()                do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()                do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()       do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()      do { TRISCbits.TRISC7 = 0; } while(0)

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