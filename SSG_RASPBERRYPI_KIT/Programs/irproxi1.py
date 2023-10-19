# connect BOARD PIN 7  OR GPIO 4 TO DOUT PIN of IR PROXI
# CONNECT BOARD PIN 5 OR GPIO 3 TO LED PIN
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

GPIO.setup(7,GPIO.IN)
GPIO.setup(5,GPIO.OUT)

while True:
    val=GPIO.input(7)
#     print(val)
    if val==1:
        GPIO.output(5,GPIO.HIGH)
        print('OBJECT DETECTED')
    else:
        GPIO.output(5,GPIO.LOW)
        print('OBJECT NOT DETECTED')
        
        
sleep.time(100) 
        