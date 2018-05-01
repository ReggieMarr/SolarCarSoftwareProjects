/* 
 * File:   bms_proto2018.c
 * Author: Thomas
 * 
 * 
 * Created on March 19, 2018, 10:50 PM
 */
#include "bms_proto2018.h"
#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>


#define _XTAL_FREQ 8000000
#define UART_FREQ 125000
#define CRC16 0xa001 //crc16 polynomial used for check bits

//BQ76PL455 FRAME INITIALIZATION BYTE FIELDS
#define BROADCMD_WRITE8    0xF1
#define BROADCMD_WRITE16   0xF2
#define BROADCMD_READ8     0XE1
#define BROADCMD_READ16    0xE2
#define GROUPCMD_WRITE8    0xA1
#define GROUPCMD_WRITE16   0xA2
#define GROUPCMD_READ8     0xB1
#define GROUPCMD_READ16    0xB2
#define SINGLECMD_WRITE8   0x11
#define SINGLECMD_WRITE16  0x12
#define SINGLECMD_READ8    0x01
#define SINGLECMD_READ16   0x02


void new_delaly_ms(unsigned int delay);
void AFE_SetAddress(int num_devices);
void AFE_Config();
void AFE_ConfigSample();
void AFE_ConfigVoltSample();
void AFE_ConfigOversample();
void AFE_ConfigCheckFault();
void AFE_ConfigCellSelect();

uint16_t gen_crc16(const uint8_t *buf, uint16_t len);
uint16_t crc16_ibm(uint8_t *buf, uint16_t len);
void send_string(const char *Txdata);
/*
 * 
 */
int main(int argc, char** argv){
    unsigned char config = 0, spbrg = 0, baudconfig = 0, i=0;
    unsigned char Txdata = 0x69;
    unsigned int counter = 0, data = 0xF21010E00000;
    unsigned int *p_data;
    uint16_t crc = 0;
    
    p_data = &data;
    SYSTEM_Initialize();
    send_string("USART Initialization Complete\n");
    
    //INTERRUPT_GlobalInterruptEnable();
    //INTERRUPT_PeripheralInterruptEnable();
    
    TRISA = 0x00;
    //crc = crc16_ibm(p_data,4);
    crc = gen_crc16(p_data,48);
    while(1){
        LATA = 0x01;
        __delay_ms(250);
        LATA = 0x00;
        __delay_ms(250);
        
        //send_string("6969");
        EUSART1_Write(crc);
        counter++;

    }

    
    return (EXIT_SUCCESS);
}

void new_delay_ms(unsigned int delay){
    unsigned int i = 0;
    for(i = 0;i++; i < delay){
        __delay_ms(1);
    }
    
}

void AFE_SetAddress(int num_devices){
    uint32_t message;
    unsigned int *p_message;
    uint16_t message_crc;
    uint8_t device_num = 0x00;
    
    message = 0xF21000F0;
    p_message = &message;
    message_crc = crc16_ibm(p_message,32);
    
    //F2 - broadcast write command
    //10 write to comm config reg
    //00 - set baud to 125k
    //F0 - enable comm interfaces
    
    EUSART1_Write(message);
    EUSART1_Write(message_crc);
    
    //config devices to use auto-address mode to select address
    message = 0xF10E10; 
    message_crc = crc16_ibm(p_message,24);
    EUSART1_Write(message);
    EUSART1_Write(message_crc);
    
    //config devices to enter auto-address mode
    message = 0xF10E10; 
    message_crc = crc16_ibm(p_message,24);
    EUSART1_Write(message);
    EUSART1_Write(message_crc);
    
    //cycle through each device and set address
    message = 0xF10A00;
    for(int i = 0; i < num_devices; i++){
        message = message ^ device_num;
        message_crc = crc16_ibm(p_message,24);
        EUSART1_Write(message);
        EUSART1_Write(message_crc);
        device_num++;
    }
    
    
    
    //EUSART1_Write(uint8_t address);
        
}

uint16_t crc16_ibm(uint8_t *buf, uint16_t len){
    uint16_t crc = 0;
    uint16_t j;
    int bits_read = 0, bit_flag;
    
    while(len > 0){
        if((crc & 0x0001) == ((*buf >> bits_read) & 0x0001)){
            crc >>= 1;
        }
        else{
            crc >>= 1;
            crc ^= CRC16;
        }
                
        bits_read++;
        if(bits_read > 7){
            bits_read = 0;
            len--;
            buf++;
        }
    }
    
    return crc;
}

uint16_t gen_crc16(const uint8_t *buf, uint16_t len){
    uint16_t crc = 0;
    int j;
    
    while(len--){
        crc ^= *buf++;
        
        for(j = 0; j < 8; j++){
            crc = (crc >> 1) ^ ((crc & 1) ? 0x8005 : 0);
        }
    }
    
    return crc;
}

void send_string(const char *Txdata){
    while(*Txdata){
        EUSART1_Write(*Txdata++);
    }
}

void AFE_Config();
void AFE_ConfigSample();
void AFE_ConfigVoltSample();
void AFE_ConfigOversample();
void AFE_ConfigCheckFault();
void AFE_ConfigCellSelect();