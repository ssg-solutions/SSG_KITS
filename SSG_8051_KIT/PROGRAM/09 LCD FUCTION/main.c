/****************************************************
       Lesson  : 9
 	   Neme    : LCD FUCTIONS
	   Details : The LCD has two line and each line has 16 character
	   			 the lcd works here 4 bit mode 
				 the display is show various fuction of lcd
******************************************************/
#include<REG51.H>
//Fuction Prototypes
void delay(unsigned int);
void lcd_string(unsigned char *p);
void lcd_data(unsigned char );
void lcd_cmd(unsigned char );


sbit EN = P3^2;
sbit RS = P3^3;
sbit RW = P3^4;
sbit light = P3^5;

#define lcddata P1;

// Program Starts Here
void main()
{
	 light=0;
	 lcd_cmd(0x38);	//LCD 4 bit Mode
	 delay(1);
	 lcd_cmd(0x06);	// display move cursor to right	
	 delay(1);
	 lcd_cmd(0x0C);	// LCD On, & cursor	OFF
	 delay(1);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_cmd(0x80);	// LCD start 1st line
	 delay(1);
	 lcd_string("     HELLO     ");
	 delay(100);
	 lcd_cmd(0xc0);	 // LCD start 2nd line
	 delay(1);
     lcd_string(" AND WELCOME ");
	 delay(400);
	 while(1)
	 {
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("LCD FUCTIONS   ");
	 delay(400);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("FIRST LINE   ");
	 delay(1);
	 delay(400);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_cmd(0xc0);	 // LCD start 2nd line
	 delay(1);
	 lcd_string("SECOND LINE   ");
	  delay(400);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("CURSOR ON   ");
	 delay(1);
	 lcd_cmd(0xc0);	 // LCD start 2nd line
	 lcd_cmd(0x0E);	 // CURSOR ON
	 delay(500);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("CURSOR OFF  ");
	 delay(1);
	 lcd_cmd(0xc0);	 // LCD start 2nd line
	 lcd_cmd(0x0C);	 // CURSOR OFF
	 delay(500);
     lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("CURSOR BLINK");
	 delay(1);
	 lcd_cmd(0xc0);	 // LCD start 2nd line
	 lcd_cmd(0x0F);	 // CURSOR BLINK
	 delay(500);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("CURSOR  RIGHT");
	 delay(1);
	 lcd_cmd(0xc0);	 // LCD start 2nd line
	 lcd_cmd(0x14);	 // CURSOR RIGHT
	 delay(100);
	 lcd_cmd(0x14);	 // CURSOR RIGHT
	 delay(100);
	 lcd_cmd(0x14);	 // CURSOR RIGHT
	 delay(100);
	 lcd_cmd(0x14);	 // CURSOR RIGHT
	 delay(100);
	 lcd_cmd(0x14);	 // CURSOR RIGHT
	 delay(100);
	 delay(500);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("CURSOR  LEFT");
	 delay(1);
	 lcd_cmd(0xc5);	 // LCD start 2nd line
	 lcd_cmd(0x10);	 // CURSOR LEFT
	 delay(100);
	 lcd_cmd(0x10);	 // CURSOR LEFT
	 delay(100);
	 lcd_cmd(0x10);	 // CURSOR LEFT
	 delay(100);
	 lcd_cmd(0x10);	 // CURSOR LEFT
	 delay(100);
	 lcd_cmd(0x10);	 // CURSOR LEFT
	 delay(100);
	 delay(500);
	 lcd_cmd(0x01);	 // LCD Clear 
	 lcd_cmd(0x0C);	 // CURSOR OFF
	 delay(1);
	 lcd_string("LCD OFF");
	 delay(200);
	 light=1;
	 lcd_cmd(0x0A);	 // LCD OFF
	 delay(500);
	 lcd_cmd(0x01);	 // LCD Clear 
	 delay(1);
	 lcd_string("LCD ON");
	 delay(1);
	 light=0;
	 lcd_cmd(0x0C);	 // LCD ON
	 delay(500);
     }
	
}

void lcd_string(unsigned char *p)
{
	while(*p != '\0')
	{
	lcd_data(*p);
	p++;
	}
}

void lcd_data(unsigned char x)
{
  RW=0;
  RS=1;
  P1 = x;
  EN=1;
  delay(1);
  EN=0;
 }

void lcd_cmd(unsigned char z)
{
  RW=0;
  RS=0;
  P1 = z;
  EN =1;
  delay(1);
  EN=0;
 }



void delay(unsigned int tt)
{
 	unsigned int a,b;
 	for(a=0;a<tt;a++)
		{
			for(b=0;b<1000;b++)
			;
		}
}