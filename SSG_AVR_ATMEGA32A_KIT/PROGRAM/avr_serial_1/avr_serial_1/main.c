/*
 * avr_serial_1.c
 *
 * Created: 12-Oct-23 11:10:53 PM
 * Author : user
 */ 
// This code demonstrates transmission of the printable charecters (ascii 33 to 125) that can be received on PC through putty app.
#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>

void usart_init(char baud)                              // initialsation of usart
{
	UBRRL=baud;                                        // setting the baud rate
	UCSRB=(1<<RXEN)|(1<<TXEN);//|(1<<RXCIE);              // enable transmiter & receiver, along with Rx intrrupt
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);        // 1 stop bit, 8 bit per character
}

void transmit_data( unsigned char data)                 // function to transmit data
{
	while(!(UCSRA & (1<<UDRE)));                       // wait for empty transmit buffer
	UDR=data;                                      // sending data
	
}


int main(void)
{
	DDRB|=(1<<PB3);
	PORTB|=(1<<PB3);
	char data = 'c';
	LCDInit(LS_NONE);

	LCDClear();
	LCDWriteString("AVR_UART");
	LCDWriteStringXY(0,1,"Tx_chk!!");//

	_delay_ms(5000);
	LCDClear();
	
	usart_init(51);// baudrate set to 1200,  baud_rate_factor = (F_CPU)/ (16 x baud rate) - 1 = (1MHz)/(16 x 1200)  -  1  = 51

    while (1) 
    {
		LCDGotoXY(0,0);
		LCDData(data);
		transmit_data(data);
		_delay_ms(1000);
		data++;
		if(data>125)
		{
			data = 33;
		}
    }
}

