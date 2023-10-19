#CONNECT GPIO 18 TO LED PIN & GPIO 23 TO SWITCH
import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

led1=4
led2=17
led3=27
led4=22

GPIO.setup(led1,GPIO.OUT)
GPIO.setup(led2,GPIO.OUT)
GPIO.setup(led3,GPIO.OUT)
GPIO.setup(led4,GPIO.OUT)
GPIO.setup(23,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setup(24,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setup(7,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setup(8,GPIO.IN,pull_up_down=GPIO.PUD_UP)
while True:
    GPIO.output(led1,GPIO.LOW)
    GPIO.output(led2,GPIO.LOW)
    GPIO.output(led3,GPIO.LOW)
    GPIO.output(led4,GPIO.LOW)
    input_state1=GPIO.input(23)
    input_state2=GPIO.input(24)
    input_state3=GPIO.input(7)
    input_state4=GPIO.input(8)
    if input_state1==False:
        GPIO.output(led1,GPIO.HIGH)
        print('BUTTON PRESSED')
         
    if input_state2==False:
        GPIO.output(led2,GPIO.HIGH)
        print('BUTTON PRESSED')
        
    if input_state3==False:
        GPIO.output(led3,GPIO.HIGH)
        print('BUTTON PRESSED')
        
    if input_state4==False:
        GPIO.output(led4,GPIO.HIGH)
        print('BUTTON PRESSED')
time.sleep(1)
    
    
