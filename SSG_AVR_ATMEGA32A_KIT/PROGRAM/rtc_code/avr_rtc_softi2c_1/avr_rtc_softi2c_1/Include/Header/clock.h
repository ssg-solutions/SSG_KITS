
#ifndef _CLOCK_H
#define _CLOCK_H

#define BOOL uint8_t

#include "ds1307_soft_i2c.h"
#include "clock.h"

//Initialization Function
BOOL ClockInit();

//Get Function
uint8_t GetSecond();
uint8_t GetMinute();
uint8_t GetHour();
uint8_t GetAmPm();

//Set Function
BOOL SetSecond(uint8_t sec);
BOOL SetMinute(uint8_t min);
BOOL SetHour(uint8_t hr);
BOOL SetAmPm(BOOL pm);	


//Time as string e.g. "12:45:33 PM"
BOOL GetTimeString(char *Time);

//Ask user to enter Current Time using LCD and Keypad
//Then saves them to DS1307 RTC module.
BOOL SetTimeAuto();


#endif
