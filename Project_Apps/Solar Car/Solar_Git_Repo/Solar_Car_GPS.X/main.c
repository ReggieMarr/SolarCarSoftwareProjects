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

// Program to Interface GPS with PIC18F4550 Microcontroller


#include "mcc_generated_files/mcc.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <ctype.h>
#include "math.h"

unsigned char getString(int testSize);
void send_string(const char *x);
void fillString(unsigned char *outputString,const unsigned char *stringSource,int startOfCycle);
float cvtGPStoDecimal(const unsigned char *inputGPS,bool latMode);
/*
                         Main application
 */


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
    
    //not allowed to have dynamic memory allocation in XC8 compilers
    unsigned char longi_data[12];//*longi_data= (unsigned char*)malloc(12*sizeof(unsigned char));
    unsigned char lati_data[12];//*lati_data = (unsigned char*)malloc(12 *sizeof(unsigned char));
    unsigned char data,value=0;
    unsigned int i=0,pos;

    uCAN_MSG *gpsMSG;
    gpsMSG->frame.idType = 1;//dSTANDARD_MSG_ID_2_OB
    gpsMSG->frame.id = 0x14;
    gpsMSG->frame.dlc = 8; //(Data Length Code) telling how many bytes im sending
    //to set data just refer to one or all of the 8 bytes allowed per msg
    union coordinate{
    float decimal;
    unsigned char byteArray[sizeof(float)];
    };

    union coordinate latitude;
    union coordinate longitude;
    //this should actually be const qualified but as of right now this is not possible
    volatile unsigned char rawData[60];//*rawData = (unsigned char*)malloc(60 *sizeof(unsigned char));
    
    bool gotGPS = false;
    unsigned char testString = "GPRMC\0"; //recommended minimum specific GNSS data
//should also test for GPLL (Global Position - Lat Long)
//and GPGGA (Global Position System Fix Data)    
    
    while(1)
    {
        /*
         * Here we start the while loop, we will first read the first data bit for a $ char
         * this signifys a likely valid NMEA sentence from the gps module.
         * This is the recommended method for getting data but for our purposes may be depreciated in the future
         * if this fails we call a function to check a section of the incoming string for a match with GPRMC
         * this signifys a likely valid nema sentence  
         */
        gotGPS = false;
        data=EUSART1_Read(); // Check the string '$GPGGA,'
        //send_string("The Retired Life");
        //data = '$';
        if(data=='$')
        {
            //gotGPS = true;
            int count = 0;
            data = EUSART1_Read();
            while(data != '*')
            {            
                if(count < 60)//data != '$')
                {
                    rawData[count] = data;
                    count++;
                    data = EUSART1_Read();
                }
                else
                {
                    break;
                } 
            }
        }
        else if(strcmp(getString(4),testString) == 0)
        {
            gotGPS = true;
            int count = 0;
            data = EUSART1_Read();
            while(data != '*')
            {            
                if(count < 60)//data != '$')
                {
                    rawData[count] = data;
                    count++;
                    data = EUSART1_Read();
                }
                else
                {
                    break;
                } 
            }
        }
        

        if(gotGPS)
        {
            float latDec = 0,longDec = 0;

            gotGPS = false;
            for(int rawCycle = 0;rawCycle<60;rawCycle++)
            {
                if(rawData[rawCycle] == 'N' || rawData[rawCycle] == 'S')
                {
                    fillString(longi_data,rawData,rawCycle);
                    bool testString = false;
                    
                    for(int i = 0;i<5;i++)
                    {
                        testString = isalnum(longi_data[i]);
                        if(!testString) break;
                    }
                    
                    for(int i = 6;i<10;i++)
                    {
                        testString = isalnum(longi_data[i]);
                        if(!testString) break;
                    }
                    
                    if(testString)
                    {
                        longDec = cvtGPStoDecimal(longi_data,false);
    //                    gotGPS = (longDec != 0) ? true : false;
                        longitude.decimal = longDec;//cvtGPStoDecimal(longi_data,false);
                        //longDec = longitude.decimal;
                        int testInt = (int)longDec;//longitude.decimal;
                        gotGPS = (testInt != 0) ? true : false;
                    }
                    else
                    {
                        gotGPS = false;
                    }

                }
                else if(rawData[rawCycle] == 'A' || rawData[rawCycle] == 'V')
                {
                    fillString(lati_data,rawData,rawCycle);
                    bool testString = false;
                    for(int i = 0;i<4;i++)
                    {
                        testString = isalnum(lati_data[i]);
                        if(!testString) break;
                    }
                    
                    for(int i = 5;i<10;i++)
                    {
                        testString = isalnum(lati_data[i]);
                        if(!testString) break;
                    }
                    
                    if(testString)
                    {
                        latDec = cvtGPStoDecimal(lati_data,true);
    //                    gotGPS = (latDec != 0) ? true : false;
                        latitude.decimal = latDec;//cvtGPStoDecimal(lati_data,true);
                        //latDec = latitude.decimal;
                        int testInt = (int)latDec;//latitude.decimal;
                        gotGPS = (testInt != 0) ? true : false;
                        //if(test)
                    }
                    else
                    {
                        gotGPS = false;
                    }

                }   
            }
            
            if(gotGPS)
            {
                    /*
     How to: Receive
    Example for how to set data using bitwise operations for CANbus
     this will store gpsLat over 4 bytes
    data0 = (gpsLAT&0x00FF); //this gets the LSB
    data1 = (8>>gpsLAT)&0x00FF; 
    
     * This all happens to make argument for CAN_Transmit
     *  * for(int i = 0;i<4;i++)
     * {
     * datai = ((8*i)>>gpsLAT)(gpsLAT&0x00FF); //note in standard we cannot refer to the data as an array
     * }
     * once weve set the data bytes we pass the uCAN_MSG by reference to the transmit method      
    
    How to: Transmit
     Example for how to receive CANbus msg data
     To get this we pass our gps integer var by reference and it is populated by the can recieve ISR
     To rebuild (on the other side)
     * gpsLAT = data3<<24|data2<<16|data1<<8|data0;
     
     */
                int dataCount = 0;
//                unsigned char *latBytePointer = (char*)&latDec;
                unsigned char gpsByte;
                size_t testSize = sizeof(float);
                gpsByte = latitude.byteArray[dataCount];
                gpsMSG->frame.data0 = gpsByte;//(unsigned char)(((dataCount*8)>>latitude.byteArray))&0xFF;
                dataCount++;
                gpsByte = latitude.byteArray[dataCount];
                gpsMSG->frame.data1 = gpsByte;//((dataCount*8)>>latitude.byteArray)&0xFF;
                dataCount++;
                gpsByte = latitude.byteArray[dataCount];
                gpsMSG->frame.data2 = gpsByte;//((dataCount*8)>>latByte)&0xFF;
                dataCount++;
                gpsByte = latitude.byteArray[dataCount];
                gpsMSG->frame.data3 = gpsByte;//((dataCount*8)>>latitude.byteArray)&0xFF;
                dataCount=0;
                //gpsByte = longitude.byteArray[dataCount];
                gpsMSG->frame.data4 = gpsByte;//((dataCount*8)>>latitude.byteArray)&0xFF;
                dataCount++;
                gpsByte = longitude.byteArray[dataCount];
                gpsMSG->frame.data5 = gpsByte;//((dataCount*8)>>latitude.byteArray)&0xFF;
                dataCount++;
                gpsByte = longitude.byteArray[dataCount];
                gpsMSG->frame.data6 = gpsByte;//((dataCount*8)>>latitude.byteArray)&0xFF;
                dataCount++;
                //gpsByte = longitude.byteArray[dataCount];
                gpsMSG->frame.data7 = gpsByte;//((dataCount*8)>>latitude.byteArray)&0xFF;
                dataCount++;
                
                int testCan = 0;
                
                do
                {
                    testCan = CAN_transmit(&gpsMSG);
                    
                    __delay_ms(500);
                } while(testCan != 1);
                

            }
            
            gotGPS = false;
        }
    
        
        memset(rawData, 0,sizeof(rawData));
        memset(lati_data, 0,sizeof(lati_data));
        memset(longi_data, 0,sizeof(longi_data));
        __delay_ms(500);
        
            
    }
    
}

unsigned char getString(int testSize)
{
    int testCycle = 0;
    unsigned char *testString = "GPRMC\0";
    testSize = strlen(testString);
    while(testCycle < testSize)
    {
        testString[testCycle] = EUSART1_Read();
        testCycle++;
    }
    
    return testString;
}

void send_string(const char *x)
{
    while(*x)
    {
        EUSART1_Write(*x++);
    }
}

void fillString(unsigned char *outputString,const unsigned char *stringSource,int startOfCycle)
{
    unsigned int findCycle = startOfCycle+2,fillCycle=0;

    unsigned int commaFound = 0;//false;
    
    unsigned char currentChar;
    
    while(commaFound < 2 && findCycle < 60)
    {
        currentChar = stringSource[findCycle];
        //if(stringSource[findCycle] == ',')
        if(currentChar == ',')
        {
            commaFound++;
        }
        else
        {
            outputString[fillCycle] = currentChar;//stringSource[findCycle];
            fillCycle++;
        }
        findCycle++;
    }
}

//this is used to convert the GPS to a decimal format
//latitude comes in DDMM.mmmm format whereas longitude comes in DDDMM.mmmm
//we get the data from the char array and then we convert it into the proper format
//which will look like DD.MMMMM or DDD.MMMMM where the coordinates are shown as a float
//from -90 to 90 (or -180 to 180 for longitude)
float cvtGPStoDecimal(const unsigned char *inputGPS,bool latMode)
{
    float convertedGPS;
    
    if(latMode)
    {
        unsigned char tempStr[] = "01.012345\0";
        memcpy(tempStr,inputGPS,9);
        
        convertedGPS = (float)((inputGPS[8] == 'S') ? -1*atof(tempStr) : atof(tempStr));
    }
    else
    {
        unsigned char tempStr[] = "012.012345\0";
        memcpy(tempStr,inputGPS,10);        
        
        convertedGPS = (float)((inputGPS[11] == 'W') ? (-1*atof(tempStr)) : (atof(tempStr)));
    }
    //the Coordinates come in the format of DDDMM.mmmmm (or DDMM.mmmmm in the case of latitude)
    //we want to converted to proper decimal formating (DDD.ddddddd)
    //this requires moving the decimal and dividing the MM.mmmmm part by 60
    convertedGPS /= 100;
    double decPart,intPart;
    
    decPart = modf(convertedGPS,&intPart);
    
    decPart = (decPart*100)/60;
    convertedGPS = intPart + decPart;

    return convertedGPS;
}

/**
 End of File
*/