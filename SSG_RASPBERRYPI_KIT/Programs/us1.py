# connect BOARD 38 TO ECHO &40 TO TRIG
import RPi.GPIO as GPIO
import time
TRIG=21
ECHO=20
GPIO.setmode(GPIO.BCM)
while True:
    print('DISTANCE')
    GPIO.setup(TRIG,GPIO.OUT)
    GPIO.setup(ECHO,GPIO.IN)
    GPIO.output(TRIG,False)
    print('waiting')
    time.sleep(0.5)
    GPIO.output(TRIG,True)
    time.sleep(0.00001)
    GPIO.output(TRIG,False)
    while GPIO.input(ECHO)==0:
        pluse_start=time.time()
    while GPIO.input(ECHO)==1:
        pluse_end=time.time()
    pluse_duration=pluse_end-pluse_start
    distance=pluse_duration*17150
    distance=round(distance,2)
    print('distance:',distance,'c m')
    time.sleep(0.5)
                
                
                