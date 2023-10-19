
const int in_1 = 8 ;
const int in_2 = 9 ;


void setup()
{
pinMode(in_1,OUTPUT) ;  
pinMode(in_2,OUTPUT) ;
}

void loop()
{
//For Clock wise motion 

digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;

delay(3000) ;     

digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(1000) ;

//For Anti Clock-wise motion 
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;

delay(3000) ;

digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,HIGH) ;
delay(1000) ;
 }
