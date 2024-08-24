/*
 * rtc.c
 *
 * Created: 01-08-2024 17:58:04
 * Author : Asmita Deshpande
 */ 

/*
 * avr_lcd_1.c
 *
 * Created: 10-Oct-23 9:25:00 AM
 * Author : user
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include <lcd.h>
#include "clock.h"


void Wait()
{
	uint8_t i;
	for(i=0;i<20;i++)
		_delay_loop_2(0);
}


void write_new_time(void)
{
	LCDClear();
	LCDWriteString("press1toWrtNew");
	LCDWriteStringXY(0,1,"newtime, 2toExit");
	
	while(1)
	{
		int i;
		i = PINA;
		i = i & 0x0f;
		if (i == 0x07)
		{
			LCDClear();
			LCDWriteString("writing_newTime");
			PORTC=0xef;
			uint8_t hours = 4, minutes = 52, seconds = 0, meridian = 1;// change these values if you want to reset the time
			
			SetHour(hours);
			SetMinute(minutes);
			SetSecond(seconds);
			SetAmPm(meridian);
			_delay_ms(3000);
			PORTC=0xff;
			return;
		}
		if (i == 0x0b)
		{
			PORTC=0xdf;
			LCDClear();
			LCDWriteString("SwitchingToRead");
			LCDWriteStringXY(0,1,"mode....");
			_delay_ms(3000);
			PORTC=0xff;
			return ; 
			//goto back2main;
		}
		_delay_ms(100);
	}
	
}
int main()
{
	DDRA=0x00;
	PORTA =0xff;
	DDRC=0xff;
	PORTC=0xff;

	//Wait Util Other device startup
	_delay_ms(500);

	//Initialize the LCD Module
	LCDInit(LS_NONE);
	DDRB|=(1<<PB3);
	PORTB|=(1<<PB3);
	LCDWriteString("LCD_initialized!");
	_delay_ms(3000);
	//ClockInit();
	//LCDWriteStringXY(0,1,"clock_init");
	//_delay_ms(1000);
	//Initialize the Clock Module
	
	if(ClockInit()==0)
	{
		//If we fail to initialize then warn user
		LCDClear();
		LCDWriteString("Error !");
		LCDWriteStringXY(0,1,"DS1307 Not Found");

		while(1); //Halt
	}
	
	write_new_time();
	
	char Time[12];	//hh:mm:ss AM/PM
	
	//Now Read and display time
	
	while(1)
	{
		
		GetTimeString(Time);
		LCDClear();
		LCDWriteString("AVR_Rocks!!!");
		LCDWriteStringXY(3,1,Time);
		
		LCDGotoXY(17,1);

		_delay_ms(500);
	}
	
	
}
