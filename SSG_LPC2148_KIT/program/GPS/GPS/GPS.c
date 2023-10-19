/*
  GPS interfacing with LPC2148(ARM7)
  http://www.electronicwings.com/arm7/gps-module-interfacing-with-lpc2148
*/

#include <lpc214x.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



char Latitude_Buffer[15],Longitude_Buffer[15],Time_Buffer[15],Altitude_Buffer[8];
char iir_val[10];
char GGA_String[150];
uint8_t GGA_Comma_Pointers[20];
char GGA[3];
volatile uint16_t GGA_Index, CommaCounter;
bool	IsItGGAString	= false;



__irq void UART0_Interrupt(void);




void delay_ms(uint16_t j)
{
    uint16_t x,i;
	for(i=0;i<j;i++)
	{
    for(x=0; x<6000; x++);    /* loop to generate 1 milisecond delay with Cclk = 60MHz */
	}
}




void UART0_init(void)
{
	PINSEL0 = PINSEL0 | 0x00000005;	/* Enable UART0 Rx0 and Tx0 pins of UART0 */
	U0LCR = 0x83;	/* DLAB = 1, 1 stop bit, 8-bit character length */
	U0DLM = 0x00;	/* For baud rate of 9600 with Pclk = 15MHz */
	U0DLL = 0x61;	/* We get these values of U0DLL and U0DLM from formula */
	U0LCR = 0x03; /* DLAB = 0 */
	U0IER = 0x00000001; /* Enable RDA interrupts */
}




void UART0_TxChar(char ch) /* A function to send a byte on UART0 */
{
	U0IER = 0x00000000; /* Disable RDA interrupts */
	U0THR = ch;
	while( (U0LSR & 0x40) == 0 );	/* Wait till THRE bit becomes 1 which tells that transmission is completed */
	U0IER = 0x00000001; /* Enable RDA interrupts */
}




void UART0_SendString(char* str) /* A function to send string on UART0 */
{  	uint8_t i = 0;
	U0IER = 0x00000000; /* Disable RDA interrupts */

	while( str[i] != '\0' )
	{
		UART0_TxChar(str[i]);
		i++;
	}
	U0IER = 0x00000001; /* Enable RDA interrupts */
}




__irq void UART0_Interrupt(void)
{
	int iir_value;
	char received_char;
	iir_value = U0IIR;
		received_char = U0RBR;
			if( received_char == '$' )
			{
				GGA_Index = 0;
				CommaCounter = 0;
				IsItGGAString = false;
			}
			else if( IsItGGAString == true )	/* If $GPGGA string */
			{
				if ( received_char == ',' )	
				{
					GGA_Comma_Pointers[CommaCounter++] = GGA_Index;	/* Store locations of commas in the string in a buffer */
				}
				GGA_String[GGA_Index++] = received_char;	/* Store the $GPGGA string in a buffer */
			}
			else if( ( GGA[0] == 'G' ) && ( GGA[1] == 'G' ) && ( GGA[2] == 'A' ) )	/* If GGA string received */
			{
				IsItGGAString = true;
				GGA[0] = GGA[1] = GGA[2] = 0;
			}
			else	/* Store received character */
			{
				GGA[0] = GGA[1];
				GGA[1] = GGA[2];
				GGA[2] = received_char;
			}
	VICVectAddr = 0x00;
}




void get_Time(void)
{	 	uint8_t time_index=0;
	uint8_t index;
	uint16_t hour, min, sec;
	uint32_t Time_value;
	U0IER = 0x00000000; /* Disable RDA interrupts */
	


	/* parse Time in GGA string stored in buffer */
	for(index = 0; GGA_String[index]!=','; index++)
	{		
		Time_Buffer[time_index] = GGA_String[index];
		time_index++;
	}	
	Time_value = atol(Time_Buffer);               /* convert string to integer */
	hour = (Time_value / 10000);                  /* extract hour from integer */
	min = (Time_value % 10000) / 100;             /* extract minute from integer */
	sec = (Time_value % 10000) % 100;             /* extract second from integer*/

	sprintf(Time_Buffer, "%d:%d:%d", hour,min,sec);
	
	U0IER = 0x00000001; /* Enable RDA interrupts */
}




void get_Latitude(uint16_t Latitude_Pointer)
{ 	uint8_t lat_index = 0;
float lat_decimal_value, lat_degrees_value;
	int32_t lat_degrees;
	uint8_t index = (Latitude_Pointer+1);
	U0IER = 0x00000000; /* Disable RDA interrupts */
	

	
	/* parse Latitude in GGA string stored in buffer */
	for(;GGA_String[index]!=',';index++)
	{
		Latitude_Buffer[lat_index]= GGA_String[index];
		lat_index++;
	}
	
	
	lat_decimal_value = atof(Latitude_Buffer);	/* Latitude in ddmm.mmmm */       
	
	/* convert raw latitude into degree format */
	lat_decimal_value = (lat_decimal_value/100);	/* Latitude in dd.mmmmmm */
	lat_degrees = (int)(lat_decimal_value);	/* dd of latitude */
	lat_decimal_value = (lat_decimal_value - lat_degrees)/0.6;	/* .mmmm/0.6 (Converting minutes to eequivalent degrees) */ 
	lat_degrees_value = (float)(lat_degrees + lat_decimal_value);	/* Latitude in dd.dddd format */
	
	sprintf(Latitude_Buffer, "%f", lat_degrees_value);
	
	U0IER = 0x00000001; /* Enable RDA interrupts */
}




void get_Longitude(uint16_t Longitude_Pointer)
{  	uint8_t long_index = 0;
	uint8_t index = (Longitude_Pointer+1);
	float long_decimal_value, long_degrees_value;
	int32_t long_degrees;
	U0IER = 0x00000000; /* Disable RDA interrupts */
	


	
	/* parse Longitude in GGA string stored in buffer */
	for(;GGA_String[index]!=',';index++)
	{
		Longitude_Buffer[long_index]= GGA_String[index];
		long_index++;
	}
	
	
	long_decimal_value = atof(Longitude_Buffer);	/* Longitude in dddmm.mmmm */
	
	/* convert raw longitude into degree format */
	long_decimal_value = (long_decimal_value/100);	/* Longitude in ddd.mmmmmm */
	long_degrees = (int)(long_decimal_value);	/* ddd of Longitude */
	long_decimal_value = (long_decimal_value - long_degrees)/0.6;	/* .mmmmmm/0.6 (Converting minutes to eequivalent degrees) */
	long_degrees_value = (float)(long_degrees + long_decimal_value);	/* Longitude in dd.dddd format */
	
	sprintf(Longitude_Buffer, "%f", long_degrees_value);
	
	U0IER = 0x00000001; /* Enable RDA interrupts */
}




void get_Altitude(uint16_t Altitude_Pointer)
{	 	uint8_t alt_index = 0;
	uint8_t index = (Altitude_Pointer+1);
	U0IER = 0x00000000; /* Disable RDA interrupts */
	

	
	/* parse Altitude in GGA string stored in buffer */
	for(;GGA_String[index]!=',';index++)
	{
		Altitude_Buffer[alt_index]= GGA_String[index];
		alt_index++;
	}
	
	U0IER = 0x00000001; /* Enable RDA interrupts */
}




int main(void)
{
	GGA_Index = 0;
	memset(GGA_String, 0 , 150);
	memset(Latitude_Buffer, 0 , 15);
	memset(Longitude_Buffer, 0 , 15);
	memset(Time_Buffer, 0 , 15);
	memset(Altitude_Buffer, 0 , 8);
	VICVectAddr0 = (unsigned) UART0_Interrupt;	/* UART0 ISR Address */
	VICVectCntl0 = 0x00000026;	/* Enable UART0 IRQ slot */
	VICIntEnable = 0x00000040;	/* Enable UART0 interrupt */
	VICIntSelect = 0x00000000;	/* UART0 configured as IRQ */
	UART0_init();
	while(1)
	{
		delay_ms(1000);
		UART0_SendString(GGA_String);
		UART0_SendString("\r\n");
		UART0_SendString("UTC Time : ");
		get_Time();
		UART0_SendString(Time_Buffer);
		UART0_SendString("\r\n");
		UART0_SendString("Latitude : ");
		get_Latitude(GGA_Comma_Pointers[0]);
		UART0_SendString(Latitude_Buffer);
		UART0_SendString("\r\n");
		UART0_SendString("Longitude : ");
		get_Longitude(GGA_Comma_Pointers[2]);
		UART0_SendString(Longitude_Buffer);
		UART0_SendString("\r\n");
		UART0_SendString("Altitude : ");
		get_Altitude(GGA_Comma_Pointers[7]);
		UART0_SendString(Altitude_Buffer);
		UART0_SendString("\r\n");		
		UART0_SendString("\r\n");
		memset(GGA_String, 0 , 150);
		memset(Latitude_Buffer, 0 , 15);
		memset(Longitude_Buffer, 0 , 15);
		memset(Time_Buffer, 0 , 15);
		memset(Altitude_Buffer, 0 , 8);
	}
}


