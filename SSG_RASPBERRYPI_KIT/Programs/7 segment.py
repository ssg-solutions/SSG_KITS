# CONNECT GPIO 4,17,27 & 22 TO A,B,C & D
import RPi.GPIO as GPIO
import time

BCD_PIN0 = 4
BCD_PIN1 = 17
BCD_PIN2 = 27
BCD_PIN3 = 22

GPIO.setwarnings(False)
# ["0000","0001","0010","0011","0100","0101","0110","0111","1000","1001"]

GPIO.setmode(GPIO.BCM)
GPIO.setup(BCD_PIN0, GPIO.OUT)
GPIO.setup(BCD_PIN1, GPIO.OUT)
GPIO.setup(BCD_PIN2, GPIO.OUT)
GPIO.setup(BCD_PIN3, GPIO.OUT)

while True:
# 0
     GPIO.output(BCD_PIN0,GPIO.LOW)
     GPIO.output(BCD_PIN1,GPIO.LOW)
     GPIO.output(BCD_PIN2,GPIO.LOW)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
#1
     GPIO.output(BCD_PIN0,GPIO.HIGH)
     GPIO.output(BCD_PIN1,GPIO.LOW)
     GPIO.output(BCD_PIN2,GPIO.LOW)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
#2      
     GPIO.output(BCD_PIN0,GPIO.LOW)
     GPIO.output(BCD_PIN1,GPIO.HIGH)
     GPIO.output(BCD_PIN2,GPIO.LOW)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
#3      
     GPIO.output(BCD_PIN0,GPIO.HIGH)
     GPIO.output(BCD_PIN1,GPIO.HIGH)
     GPIO.output(BCD_PIN2,GPIO.LOW)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
#4      
     GPIO.output(BCD_PIN0,GPIO.LOW)
     GPIO.output(BCD_PIN1,GPIO.LOW)
     GPIO.output(BCD_PIN2,GPIO.HIGH)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
#5
     GPIO.output(BCD_PIN0,GPIO.HIGH)
     GPIO.output(BCD_PIN1,GPIO.LOW)
     GPIO.output(BCD_PIN2,GPIO.HIGH)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
# 6
     GPIO.output(BCD_PIN0,GPIO.LOW)
     GPIO.output(BCD_PIN1,GPIO.HIGH)
     GPIO.output(BCD_PIN2,GPIO.HIGH)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
# 7
     GPIO.output(BCD_PIN0,GPIO.HIGH)
     GPIO.output(BCD_PIN1,GPIO.HIGH)
     GPIO.output(BCD_PIN2,GPIO.HIGH)
     GPIO.output(BCD_PIN3,GPIO.LOW)
     time.sleep(1)
# 8
     GPIO.output(BCD_PIN0,GPIO.LOW)
     GPIO.output(BCD_PIN1,GPIO.LOW)
     GPIO.output(BCD_PIN2,GPIO.LOW)
     GPIO.output(BCD_PIN3,GPIO.HIGH)
     time.sleep(1)
# 9
     GPIO.output(BCD_PIN0,GPIO.HIGH)
     GPIO.output(BCD_PIN1,GPIO.LOW)
     GPIO.output(BCD_PIN2,GPIO.LOW)
     GPIO.output(BCD_PIN3,GPIO.HIGH)
     time.sleep(1)
     
