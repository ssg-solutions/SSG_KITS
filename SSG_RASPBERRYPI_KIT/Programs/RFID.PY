# Setting up Raspberry Pi for Serial Communication BEFORE TO RUN PROGRAM 
# CONNECT TX of RFID to BOARD of 10 PIN OR RX OF RASPBERRY PI BOARD
import time
import serial
          
      
data = serial.Serial(
                    port='/dev/ttyS0',
                    baudrate = 9600,
                    parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE,
                    bytesize=serial.EIGHTBITS
                    )
                    #timeout=1 # must use when using data.readline()
                    #)
print (" ")
          
try:     
   while 1:
         #x=data.readline()#print the whole data at once
         #x=data.read()#print single data at once
         
         print ("Place the card")
         x=data.read(12)#print upto 10 data at once and the 
                        #remaining on the second line
         
#          if x=="13004A29E191":
#              print ("Card No - ",x)
#              print ("Welcome Bala")
#              print (" ")
#          
#          elif x=="0004281950065":
#              print ("Card No - ",x)
#              print ("Welcome Teja")
#              print (" ")
#          else:
#              print ("Wrong Card.....")
#              print (" ")        
         
         print (x)

except KeyboardInterrupt:
       data.close()
