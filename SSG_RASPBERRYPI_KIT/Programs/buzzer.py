# connect BOARD 16 WITH BUZZER
import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
buzzer=23
GPIO.setup(buzzer,GPIO.OUT)
while True:
    GPIO.output(buzzer,GPIO.HIGH)
    time.sleep(2)
    GPIO.output(buzzer,GPIO.LOW)
    time.sleep(2)
    