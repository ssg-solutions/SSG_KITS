# connect RX & TX of bluetooth with TX & RX of RPI4 and LED PIN to GPIO  27,brfore that Set up Raspberry Pi for Serial Communication
# by entering the  command sudo raspi-config in terminal-->select interface options--->serial option--->NO-->YES-->sudo reboot
#sudo raspi-config
import RPi.GPIO as GPIO
import serial
value = serial.Serial("/dev/ttyS0",baudrate=9600)

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(27,GPIO.OUT)

while True:
    data = str (int(value.readline(),2))
    print(data)
    if data =="1":
        GPIO.output(27,GPIO.HIGH)
        print("LED1:ON")
    else:
        GPIO.output(27,GPIO.LOW)
        print("LED1:OFF")
        
