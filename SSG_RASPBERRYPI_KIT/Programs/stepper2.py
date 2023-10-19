# connect BOARD 7,11,13 &15 OR GPIO 4,17,27 & 22 TO B1,B2,B3 &B4 respectively
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
#GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)


ControlPin=[4,17,27,22]

for pin in ControlPin:
    GPIO.setup(pin,GPIO.OUT)
    GPIO.output(pin,1)
    
seq=  [[1,1,0,0],
       [0,1,1,0],
       [0,0,1,1],
       [1,0,0,1],
 ]      

rotationNeeded=0
rotationCount=0
while(1):
    rotationNeeded==0
    print('/n')
    userInput=input('e-exit,enter rotation number')
    print('/n')
    if userInput=='e':
        break;
    
    rotationNeeded=int (userInput)
    rotationCount=50* rotationNeeded
    
    for i in range(rotationCount):
        for fullstep in range(4):
            for pin in range(4):
                GPIO.output(ControlPin[pin],seq[fullstep][pin])
                time.sleep(0.001)
                
GPIO.cleanup()     

