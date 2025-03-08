#ifndef _DS1307_SOFT_H_
#define _DS1307_SOFT_H_

#define BOOL uint8_t

#define DS1307_SLA_W 0XD0
#define DS1307_SLA_R 0XD1

#define TRUE 	1
#define FALSE 	0

//Public Functions

void DS1307Init(void);

/***************************************************

Function To Write Internal Registers of DS1307
---------------------------------------------

address : Address of the register
data: value to write.


Returns:
0= Failure
1= Success
***************************************************/
BOOL DS1307Write(uint8_t address,uint8_t data);


/***************************************************

Function To Read Internal Registers of DS1307
---------------------------------------------

address : Address of the register
data: value of register is copied to this.


Returns:
0= Failure
1= Success
***************************************************/
BOOL DS1307Read(uint8_t address,uint8_t *data);


#endif
