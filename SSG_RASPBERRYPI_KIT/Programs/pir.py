# connect GPIO 23 TO PIR OUT
# connect GPIO 3 TO Led pin
from gpiozero import MotionSensor
import RPi.GPIO as GPIO
import time
from time import sleep
pir = MotionSensor(23)
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(3,GPIO.OUT)
while True:
	pir.wait_for_motion()
	GPIO.output(3, 1)
	print("Motion detected")
# 	time.sleep(5)
	pir.wait_for_no_motion()
	GPIO.output(3, 0)
	print("no motion detected")