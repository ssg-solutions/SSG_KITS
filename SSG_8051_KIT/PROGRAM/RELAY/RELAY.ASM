; connect relay with port pin 3.0 of 8051
ORG 0000H
LOOP:SETB P3.0
ACALL DELAY
CLR P3.0
ACALL DELAY
SJMP LOOP


DELAY:
	MOV R0,#05
L3:	MOV R2,#255
L1: MOV R3,#255
L2: DJNZ R3,L2
	DJNZ R2,L1
	DJNZ R0,L3
	RET
	
	END