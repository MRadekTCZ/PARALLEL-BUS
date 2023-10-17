#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "main.h"
//#define BUS_RECEIVE 1
#define DATA_TO_MEM_1byte  DATA_TO_MEM_8bit
#define DATA_TO_MEM_2byte  DATA_TO_MEM_16bit
#define DATA_TO_MEM_3byte  DATA_TO_MEM_32bit


typedef long long uint64;
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

uint8 DATABYTES_TO_SEND;
uint16 ALL;

union Data_to_Bus Data_to_Bus, Bus_to_Data;

int DATA_TO_MEM_8bit(uint8 address, uint8 data, uint8* MEMORY);
int DATA_TO_MEM_16bit(uint8 address, uint16 data, uint8* MEMORY);
int DATA_TO_MEM_32bit(uint8 address, uint32 data, uint8* MEMORY);

int DATA_TO_MEM_float(uint8 address, float data, uint8* MEMORY);

int DATA_SEND_TO_FPGA(uint8 address,uint8 data);
struct DATAADD
    {
        uint8 data;
        uint8 address;
    };

union Data_to_Bus
{
	struct DATAADD DataAdd;

    struct bit_send
    {
        uint16 hex1 : 4;
        uint16 byte2 : 8;
        uint16 hex3 : 4;
    }Bit_field;

};


#ifdef extension
int DATA_TO_MEM_double(uint8 address, double data, uint8* MEMORY);
int DATA_TO_MEM_64bit(uint8 address, uint64 data, uint8* MEMORY);
#define DATA_TO_MEM_4byte  DATA_TO_MEM_64bit
#endif
