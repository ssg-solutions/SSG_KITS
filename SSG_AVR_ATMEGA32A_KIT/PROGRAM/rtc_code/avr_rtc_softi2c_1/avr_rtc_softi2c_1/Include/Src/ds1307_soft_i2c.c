
#include <avr/io.h>

#include "i2csoft.h"
#include "ds1307_soft_i2c.h"

void DS1307Init(void)
{
	SoftI2CInit();
}

/***************************************************

Function To Read Internal Registers of DS1307
---------------------------------------------

address : Address of the register
data: value of register is copied to this.


Returns:
0= Failure
1= Success
***************************************************/

BOOL DS1307Read(uint8_t address,uint8_t *data)
{
	uint8_t res;	//result
	
	//Start
	SoftI2CStart();
	
	//SLA+W (for dummy write to set register pointer)
	res=SoftI2CWriteByte(DS1307_SLA_W);	//DS1307 address + W
	
	//Error
	if(!res)	return FALSE;
	
	//Now send the address of required register
	res=SoftI2CWriteByte(address);
	
	//Error
	if(!res)	return FALSE;
	
	//Repeat Start
	SoftI2CStart();
	
	//SLA + R
	res=SoftI2CWriteByte(DS1307_SLA_R);	//DS1307 Address + R
	
	//Error
	if(!res)	return FALSE;
	
	//Now read the value with NACK
	*data=SoftI2CReadByte(0);
	
	//Error
	if(!res)	return FALSE;
	
	//STOP
	SoftI2CStop();
	
	return TRUE;
}

/***************************************************

Function To Write Internal Registers of DS1307
---------------------------------------------

address : Address of the register
data: value to write.


Returns:
0= Failure
1= Success
***************************************************/

BOOL DS1307Write(uint8_t address,uint8_t data)
{
	uint8_t res;	//result
	
	//Start
	SoftI2CStart();
	
	//SLA+W
	res=SoftI2CWriteByte(DS1307_SLA_W);	//DS1307 address + W
	
	//Error
	if(!res)	return FALSE;
	
	//Now send the address of required register
	res=SoftI2CWriteByte(address);
	
	//Error
	if(!res)	return FALSE;
	
	//Now write the value
	res=SoftI2CWriteByte(data);
	
	//Error
	if(!res)	return FALSE;
	
	//STOP
	SoftI2CStop();
	
	return TRUE;
}
