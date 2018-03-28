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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC18F26K80
        Driver Version    :  2.00
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
// Program to Interface GPS with PIC18F4550 Microcontroller
#define FREQ 12000000
#define baud 4800
#define spbrg_value (((FREQ/64)/baud)-1)
#define rs LATA.F0
#define rw LATA.F1
#define en LATA.F2
//#define lcdport LATB


/*
                         Main application
 */

unsigned char rx_data();
void tx_data(char);

void send_string(const char *x)
{

    while(*x)
    {
        EUSART1_Write(*x++);
    }
}
//void lcd_ini();
//void lcdcmd(unsigned char);
//void lcddata(unsigned char);

unsigned char longi_data[12];
unsigned char lati_data[12];
unsigned char data,value=0;
unsigned int i=0,pos;

void main()
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


//TRISB=0; // Set Port B as output port
//LATB=0;
//TRISA=0;
//LATA=0;
//SPBRG=spbrg_value; // Fill SPBRG register to set the baud rate
//TRISCbits.TRISC6 = 0; //this sets 
//TRISCbits.TRISC7 = 1;
//
//TXSTA1bits.SYNC = 0; // Async operation
//TXSTA1bits.TX9 = 0;  // No tx of 9th bit
//TXSTA1bits.TXEN = 1;  // Enable transmitter
//RCSTA1bits.RX9 = 0;  // No rx of 9th bit
//RCSTA1bits.CREN = 1; // Enable receiver
//RCSTA1bits.SPEN = 1; // Enable serial port

//lcd_ini();
while(1)
{
    unsigned char rawData[82];
    data=EUSART1_Read(); // Check the string '$GPGGA,'
    //tx_data(data); //send data
    //send_string("The Retired Life");
    //tx_data('c');
    if(data=='$')
    {
        int count = 0;
        while(data != '*')
        {
            data = EUSART1_Read();
            if(count < 80)//data != '$')
            {
                rawData[count] = data;
                count++;
            }
            else
            {
                break;
            }
            
        }
//        data=EUSART1_Read();//rx_data();
//        if(data=='G')
//        {
//            data=EUSART1_Read();//rx_data();
//            if(data=='P');
//            {
//                data=EUSART1_Read();//rx_data();
//                    if(data=='G');
//                    {
//                        data=EUSART1_Read();//rx_data();
//                        if(data=='G')
//                        {
//                        data=EUSART1_Read();//rx_data();
//                        if(data=='A')
//                        {
//                        data=EUSART1_Read();//rx_data();
//                        if(data==',')
//                        {
//                            data=EUSART1_Read();//rx_data();
//                            while(data!=',')
//                            {
//                                data=EUSART1_Read();//rx_data();
//                                for(i=0;data!='N' && data != 'S';i++)
//                                {
//                                    data=EUSART1_Read();//rx_data();
//                                    lati_data[i]=data; // Store the Latitude data   
//                                }
//                                bool fakestart = false;
//                            
//                            data=EUSART1_Read();//rx_data();
//                            if(data==',')
//                            {
//                                for(i=0;data!='E' && data != 'W';i++)
//                                {
//                                    data=EUSART1_Read();//rx_data();
//                                    longi_data[i]=data; // Store the Longitude data
//                                }
//                            }
//                            }
                            //i=0;
                            //lcdcmd(0x80);
//                                while(i<11)
//                                {
//                                    lcddata(lati_data[i]); // Print the Latitude data
//                                    i++;
//                                }
//                                i=0;
//                                lcdcmd(0xC0);
//                                while(i<12)
//                                {
//                                    lcddata(longi_data[i]); // Print the Longitude data
//                                    i++;
//                                }
//                        }
//                    }
//                }
//            }
//        }
//    }
}
//    Delay_ms(1000);
    int a = 1;
    
for(int b = 0;b<82;b++)
{
rawData[b] = 0;    
}
for(i=0;i<12;i++)
{
    data=0;
    lati_data[i]=0;
    longi_data[i]=0;
}
    

}
}

void tx_data(char sentChar)
{
    while(TXSTAbits.TRMT == 0)
    {
        //we wait for the pic to finish sending data
    }
    
    TXREG1 = sentChar;//then we set the TX pins data to this char
    
}

unsigned char rx_data(void)
{
    while(PIR1bits.RCIF==0); // Wait until RCIF gets low
    {
        if(RCSTA1bits.OERR == 1)
        {
            RCSTA1bits.OERR = 0; //clears overrun if occurs
            RCSTA1bits.CREN = 0;
            RCSTA1bits.CREN = 1;
        }
        //delay
    }
    return RCREG1; // Store data in Reception register
}

//void lcd_ini()
//{
//lcdcmd(0x38); // Configure the LCD in 8-bit mode, 2 line and 5x7 font
//lcdcmd(0x0C); // Display On and Cursor Off
//lcdcmd(0x01); // Clear display screen
//lcdcmd(0x06); // Increment cursor
//lcdcmd(0x80); // Set cursor position to 1st line, 1st column
//}

//void lcdcmd(unsigned char cmdout)
//{
//lcdport=cmdout; //Send command to lcdport=PORTB
//rs=0;
//rw=0;
//en=1;
//Delay_ms(10);
//en=0;
//}

//void lcddata(unsigned char dataout)
//{
//lcdport=dataout; //Send data to lcdport=PORTB
//rs=1;
//rw=0;
//en=1;
//Delay_ms(10);
//en=0;
//}

/**
 End of File
*/