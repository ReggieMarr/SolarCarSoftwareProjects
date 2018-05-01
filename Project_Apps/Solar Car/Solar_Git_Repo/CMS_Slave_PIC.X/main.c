/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F26K80
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "string.h"
//#include "../include/plib/i2c.h"
//#include "p18f26k80.h"
//#define USE_OR_MASKS
void mccSendI2C(uint8_t *dataToSend,uint16_t address);
void mccReceiveI2C(volatile uint8_t *dataToSend,uint16_t address);
/*
                         Main application
 */

static	uint8_t State = 0;
static	uint16_t StartTime = 0;
static	uint16_t address = 5;//(0xC0 / 2);	/* CMPS03 by Robot Electronics
										// * MCC I2C driver expect 7 bit address. */
static	uint8_t length = 1;
static	uint8_t command = 0,	data = 0;
static	I2C_MESSAGE_STATUS I2C_Wflag, I2C_Rflag;
static	uint8_t result[8];
unsigned char I2C_Recv[21];

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    //32 khz 15% DC
    //PWM2_LoadDutyValue(250);
    
    unsigned char sync_mode=0, slew=0, add1,w,data,status,length;

    for(w=0;w<20;w++)
    I2C_Recv[w]=0;
    add1=0x8;
    uint8_t *dataMCC = "Current";
    volatile uint8_t *readData = "0123456789";
    I2C_MESSAGE_STATUS sendFlag = I2C_MESSAGE_PENDING;
    while(1)
    {
        
        //I2C_MasterWrite("Current",strlen("Current"),8,&sendFlag);
        //__delay_ms(100);
        if(readData[0] == 'O' && readData[1] == 'K')
        {
            mccSendI2C("Worked!",8);
        }
        
        mccSendI2C(dataMCC,8);
        //readData = "0123456789";
        mccReceiveI2C(readData,8);
    }
       
    
}

void mccSendI2C(uint8_t *dataToSend,uint16_t address)
{
    I2C_MESSAGE_STATUS sendFlag = I2C_MESSAGE_PENDING;
    I2C_Status_Toggle();
    int timeOut = 0;
    do
    {
        if(sendFlag == I2C_MESSAGE_COMPLETE || timeOut == 10)
        {
            break;
        }
        else
        {
            timeOut++;
        }
        I2C_Status_Toggle();
        __delay_ms(60);
        I2C_MasterWrite(dataToSend,strlen(dataToSend),8,&sendFlag);
        
    }
    while(sendFlag == I2C_MESSAGE_PENDING);
}

void mccReceiveI2C(volatile uint8_t *dataToSend,uint16_t address)
{
    I2C_MESSAGE_STATUS sendFlag = I2C_MESSAGE_PENDING;
    I2C_Status_Toggle();
    int timeOut = 0;
    do
    {
        if(sendFlag == I2C_MESSAGE_COMPLETE || timeOut == 10)
        {
            break;
        }
        else
        {
            timeOut++;
        }
        I2C_Status_Toggle();
        __delay_ms(60);
        I2C_MasterRead(dataToSend,strlen(dataToSend),address,&sendFlag);
    }
    while(sendFlag == I2C_MESSAGE_PENDING);
}
/**
 End of File
*/