
//connect RX OF BLUETOOTH TO TX OF BOARD & TX OF BLUETOOYH TO RX OF BOARD AND D3 TO LED
char data = 0;           //Variable that store receive input
void setup()
{
    Serial.begin(9600);  /*Baud Rate for serial communication*/
    pinMode(3, OUTPUT); /*D3 for LED*/
}
void loop()
{
    if(Serial.available() > 0)       /*check for serial data availability*/
    {
        data = Serial.read();        /*read data coming from Bluetooth device*/
        Serial.print(data);          /*print values on serial monitor*/
        Serial.print("\n");          /*print new line*/
        if(data == '1')              /*check data value*/
            digitalWrite(3, HIGH);  /*Turn ON LED if serial data is 1*/
        else if(data == '0')         /*check data value*/
            digitalWrite(3, LOW);   /*Turn OFF LED if serial data is 0*/
    }                            
}
