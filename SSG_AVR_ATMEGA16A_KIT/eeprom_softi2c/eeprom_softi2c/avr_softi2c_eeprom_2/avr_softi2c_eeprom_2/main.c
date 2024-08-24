/*
 * this program, writes a single character variable to the specified mem address in EEPROM, and then displays it back on LCD by reading the same 
	memory location!
 *
 * Created: 11-Oct-23 3:13:28 AM
 * Author : user
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <i2csoft.h>
#include <lcd.h>

#define EEPROM_WRITE_ADDRESS		0xA0
#define EEPROM_READ_ADDRESS			0xA1

#define EE_IO_ERROR	0
#define EE_SUCCESS	1

//#define starting_address 0x0000

uint16_t starting_address = 0x0000;

bool EEWriteByte(uint16_t address,uint8_t data)
{
	SoftI2CStart();

	//SLA+W
	if(!SoftI2CWriteByte(EEPROM_WRITE_ADDRESS))
	{
		SoftI2CStop();

		//I2C i/o error

		return EE_IO_ERROR;
	}

	//Address HIGH
	if(!SoftI2CWriteByte(address>>8))
	{
		SoftI2CStop();

		//I2C i/o error
		return EE_IO_ERROR;
	}

	//Address LOW

	if(!SoftI2CWriteByte(address))
	{
		SoftI2CStop();

		//I2C i/o error
		return EE_IO_ERROR;
	}

	//Data
	if(!SoftI2CWriteByte(data))
	{
		SoftI2CStop();

		//I2C i/o error
		return EE_IO_ERROR;
	}

	SoftI2CStop();

	_delay_ms(5);

	return EE_SUCCESS;
}


bool EEReadByte(uint16_t address, uint8_t *data)
{

	SoftI2CStart();

	//SLA+W

	if(!SoftI2CWriteByte(EEPROM_WRITE_ADDRESS))
	{
		SoftI2CStop();

		//I2C i/o error
		return EE_IO_ERROR;
	}

	//Address HIGH
	if(!SoftI2CWriteByte(address>>8))
	{
		SoftI2CStop();

		//I2C i/o error

		return EE_IO_ERROR;
	}
	//Address LOW
	if(!SoftI2CWriteByte(address))
	{
		SoftI2CStop();

		//I2C i/o error
		return EE_IO_ERROR;
	}

	//Repeat Start

	SoftI2CStart();

	//SLA+R
	if(!SoftI2CWriteByte(EEPROM_READ_ADDRESS))
	{
		SoftI2CStop();

		//I2C i/o error
		return EE_IO_ERROR;
	}

	//Read + NAK
	*data=SoftI2CReadByte(0);

	SoftI2CStop();

	return EE_SUCCESS;
}



int main(void)
{
   DDRB|=(1<<PB3);
   PORTB|=(1<<PB3);
   
   
   //Initialize the LCD Module
   LCDInit(LS_NONE);
   
   LCDWriteStringXY(0,0,"SSG_Embedded_AVR");
   LCDWriteStringXY(0,1,"Hello_world!");
   
   _delay_ms(3000);
  
   char read_char, single_char = 'P';
   
   LCDClear();
    LCDWriteString("Writing ....");
  
   
   if(!EEWriteByte(starting_address, (single_char )))
		{
			LCDClear();			
			LCDWriteStringXY(0,0,"I2C i/o Error !");
			LCDWriteStringXY(0,1,"while writing.");
			while(1);//halt
		}
   
   _delay_ms(3000);
   LCDWriteStringXY(0,1,"Reading .....");
  
	if(!EEReadByte(starting_address, &read_char))
	{
		LCDClear();
		LCDWriteStringXY(0,0,"I2C i/o Error !");
		LCDWriteStringXY(0,1,"while reading.");
		while(1);//halt
	}
	_delay_ms(3000);
	
	LCDClear();
	LCDWriteString("read_char =");
	LCDData(read_char);// read char being displayed on screen
	LCDGotoXY(0,1);
	LCDWriteInt(read_char,5);// read char's int value
	LCDGotoXY(7,1);
	LCDWriteInt(starting_address,4);// home memory location
	
	_delay_ms(3000);
	
  
	
	while(1);  
   
}

