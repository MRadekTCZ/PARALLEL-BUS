#include "BUS_8bit.h"


int DATA_TO_MEM_8bit(uint8 address, uint8 data, uint8* MEMORY)
{

	*(MEMORY + address) = data;
	if (address > DATABYTES_TO_SEND) DATABYTES_TO_SEND = address;

	return 1;
}

int DATA_TO_MEM_16bit(uint8 address, uint16 data, uint8* MEMORY)
{
	union DATA16bit
	{
		uint16 data16bit;
		struct Data2x8bit
		{
			uint8 data1;
			uint8 data2;
		}Data2x8bit;
	}DATA16bit;

	DATA16bit.data16bit = data;

	*(MEMORY + address) = DATA16bit.Data2x8bit.data1;
	*(MEMORY + address + 1) = DATA16bit.Data2x8bit.data2;
	if ((address + 1) > DATABYTES_TO_SEND) DATABYTES_TO_SEND = address + 1;

	return 1;
}

int DATA_TO_MEM_32bit(uint8 address, uint32 data, uint8* MEMORY)
{
	union DATA32bit
	{
		uint32 data32bit;
		struct Data2x8bit
		{
			uint8 data1;
			uint8 data2;
			uint8 data3;
			uint8 data4;
		}Data4x8bit;
	}DATA32bit;
	DATA32bit.data32bit = data;

	*(MEMORY + address) = DATA32bit.Data4x8bit.data1;
	*(MEMORY + address + 1) = DATA32bit.Data4x8bit.data2;
	*(MEMORY + address + 2) = DATA32bit.Data4x8bit.data3;
	*(MEMORY + address + 3) = DATA32bit.Data4x8bit.data4;

	if ((address + 3) > DATABYTES_TO_SEND) DATABYTES_TO_SEND = address + 3;

	return 1;
}



int DATA_TO_MEM_float(uint8 address, float data, uint8* MEMORY)
{

	union DATA_float_32bit
	{
		float data32bit;
		struct Data2x8bit
		{
			uint8 data1;
			uint8 data2;
			uint8 data3;
			uint8 data4;
		}Data4x8bit;
	}DATA32bit;
	DATA32bit.data32bit = data;

	*(MEMORY + address) = DATA32bit.Data4x8bit.data1;
	*(MEMORY + address + 1) = DATA32bit.Data4x8bit.data2;
	*(MEMORY + address + 2) = DATA32bit.Data4x8bit.data3;
	*(MEMORY + address + 3) = DATA32bit.Data4x8bit.data4;

	if ((address + 3) > DATABYTES_TO_SEND) DATABYTES_TO_SEND = address + 3;

	return 1;
}

int DATA_SEND_TO_FPGA(uint8 address,uint8 data)
{
	//ALL = (address<<8) + data;
	Data_to_Bus.DataAdd.data = data;
	Data_to_Bus.DataAdd.address = address;
	return 1;
}
