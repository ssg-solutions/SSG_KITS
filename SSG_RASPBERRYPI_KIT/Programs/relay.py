# CONNECT BOARD 16 OR GPIO 23 WITH RELAY SIG
import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
buzzer=23
GPIO.setup(buzzer,GPIO.OUT)
while True:
    GPIO.output(buzzer,GPIO.HIGH)
    print("RELAY HIGH")
    time.sleep(0.5)
    GPIO.output(buzzer,GPIO.LOW)
    print("RELAY LOW")
    time.sleep(0.5)
    
