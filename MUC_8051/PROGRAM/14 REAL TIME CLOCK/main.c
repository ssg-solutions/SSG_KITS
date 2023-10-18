/****************************************************
       Lesson  : 14
 	   Neme    : REAL TIME CLOCK
	   Details : The ds1307 is a Real time clock from dallas
	   			it has a small 3v battery so the clock setting remains while power off
				it works on I2C protocal, 
				for more detail please see its Datasheet
******************************************************/
#include<reg52.h>
#include<stdio.h>
#include<intrins.h>

void InitSerial(void);
void DelayMs(unsigned int count);
void ReadRTC(unsigned char * buff);
void WriteRTC(unsigned char * buff);
char * Int2Day(unsigned char day);
char * Int2Month(unsigned char month);

#define ACK		1
#define NO_ACK	0
#define SLAVE	0xD0
#define WRITE   0x00
#define READ    0x01
#define ERR_ACK 0x01

unsigned char  RTC_ARR[7];  // Buffer for second,minute,.....,year
unsigned char p;
unsigned char i;

const unsigned char * DayStr[7]  =     {{"Sun"},
				   						{"Mon"},
				   						{"Tue"},
				   						{"Wed"},
				   						{"Thu"},
				   						{"Fri"},
				   						{"Sat"}};


const unsigned char * MonthStr[12]    ={{"Jan"},
										{"Feb"},
										{"Mar"},
										{"Apr"},
										{"May"},
										{"Jun"},
										{"Jul"},
										{"Aug"},
										{"Sep"},
										{"Oct"},
										{"Nov"},
										{"Dec"}};


sbit SDA  =  P3^6;	// connect to SDA pin (Data)
sbit SCL  =  P3^7;	// connect to SCL pin (Clock)
//---------------------------------------
// Main program
//---------------------------------------
void main(void)
{


	InitSerial();  		// Initialize serial port
	ReadRTC(&RTC_ARR[0]);        
//	RTC_ARR[0] = RTC_ARR[0] & 0x7F;	// enable oscillator (bit 7=0)
	//RTC_ARR[1] = 0x44;	// minute = 59
	//RTC_ARR[2] = 0x11;	// hour = 05 ,24-hour mode(bit 6=0)
	//RTC_ARR[3] = 0x02;	// Day = 1 or sunday
	//RTC_ARR[4] = 0x18;	// Date = 30
	//RTC_ARR[5] = 0x09;	// month = August
  //RTC_ARR[6] = 0x23;	// year = 05 or 2005
//	WriteRTC(&RTC_ARR[0]);	// Set RTC

    
	while(1)
	{
		ReadRTC(&RTC_ARR[0]);        
		putchar(0x0C);  // clear Hyper terminal
		printf("Day  : %s\r\n",Int2Day(RTC_ARR[3]));		
        	printf("Time : %02bX:%02bX:%02bX\r\n",RTC_ARR[2],RTC_ARR[1],RTC_ARR[0]);	    
		printf("Data : %02bX-%s-20%02bX",RTC_ARR[4],Int2Month(RTC_ARR[5]),RTC_ARR[6]);	    		
		DelayMs(1000);	// delay about 1 second
	}
}

void InitSerial(void)
{
  	SCON = 0x50;	// Setup serial port control register Mode 1: 
					// 8-bit uart var baud rate REN: enable receiver 
	TMOD |= 0x20;   // Set M1 for 8-bit autoreload timer 	
	TH1 = 0xFD;     // Set autoreload value for timer1 9600 baud 
					// with 11.0592 MHz xtal 	
	TR1 = 1;        // Start timer 1 	
	TI = 1;         // Set TI to indicate ready to xmit
}
void DelayMs(unsigned int count) 
{  
    unsigned int i;		       		
    while(count) 
	{
        i = 115; 
		while(i>0) i--;
        count--;
    }
}



//-------------------------------
// Convert BCD 1 byte to HEX 1 byte
//-------------------------------
unsigned char BCD2HEX(unsigned int BCD)
{
	unsigned char temp;
	temp=((BCD>>8)*100)|((BCD>>4)*10)|(BCD&0x0f);
	return temp;
	
}

//-------------------------------
// start I2C
//-------------------------------
void Start(void)
{
    SDA = 1;
	SCL = 1;
	_nop_();_nop_();
	SDA = 0;
	_nop_();_nop_();
	SCL = 0;
	_nop_();_nop_();
}

//-------------------------------
// stop I2C
//-------------------------------
void Stop(void)
{
	SDA = 0;	    	
	_nop_();_nop_();
	SCL = 1;
	_nop_();_nop_();
	SDA = 1;	
}

//-------------------------------
// Write I2C
//-------------------------------
void WriteI2C(unsigned char Data)
{    

	for (i=0;i<8;i++)
	{
        SDA = (Data & 0x80) ? 1:0;
		SCL=1;SCL=0;
		Data<<=1;
	}

  	SCL = 1; 
	_nop_();_nop_();
	SCL = 0;

}

//-------------------------------
// Read I2C
//-------------------------------
unsigned char ReadI2C(bit ACK_Bit)
{
    
    unsigned char Data=0;

    SDA = 1;	
	for (i=0;i<8;i++)
	{
		SCL   = 1;		
		Data<<= 1;
		Data  = (Data | SDA);		
		SCL   = 0;
		_nop_();
	}
    
 	if (ACK_Bit == 1)
	SDA = 0; // Send ACK		
	else		
	SDA = 1; // Send NO ACK				

	_nop_();_nop_();
	SCL = 1;		
	_nop_();_nop_();
	SCL = 0;
	
	return Data;
}

//-------------------------------
// Read RTC (all real time)
//-------------------------------
void ReadRTC(unsigned char * buff)
{
	
	
	Start();
	WriteI2C(0xD0);
	WriteI2C(0x00);

	Start();
	WriteI2C(0xD1);	
	*(buff+0)=ReadI2C(ACK);	// Second
	*(buff+1)=ReadI2C(ACK);	// Minute
	*(buff+2)=ReadI2C(ACK);	// hour
	*(buff+3)=ReadI2C(ACK);	// Day
	*(buff+4)=ReadI2C(ACK);	// date
	*(buff+5)=ReadI2C(ACK);	// month
	*(buff+6)=ReadI2C(NO_ACK);	// year
	Stop();		
}

//-------------------------------
// Write RTC
//-------------------------------
void WriteRTC(unsigned char *buff)
{

	Start();
	WriteI2C(0xD0);
	WriteI2C(0x00);	
	WriteI2C(*(buff+0));	
	WriteI2C(*(buff+1));
	WriteI2C(*(buff+2));
	WriteI2C(*(buff+3));
	WriteI2C(*(buff+4));
	WriteI2C(*(buff+5));
	WriteI2C(*(buff+6));	
	Stop();	
}


char * Int2Day(unsigned char day)
{
	return DayStr[day-1];
}


char * Int2Month(unsigned char month)
{
  return MonthStr[BCD2HEX(month)-1];
}
