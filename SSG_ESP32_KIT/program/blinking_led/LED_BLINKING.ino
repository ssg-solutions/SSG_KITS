


//connect RX2,TX2,D5,D18 to led1,led2,led3 led4 respectively
const int ledPin1 = 5;
const int ledPin2 = 18;
const int ledPin3 = 17;
const int ledPin4 = 16;
void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  pinMode (ledPin4, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (ledPin1, HIGH);  
  digitalWrite (ledPin2, HIGH); 
  digitalWrite (ledPin3, HIGH); 
  digitalWrite (ledPin4, HIGH); 
  delay(500);
  digitalWrite (ledPin1, LOW);  
  digitalWrite (ledPin2, LOW);  
  digitalWrite (ledPin3, LOW);  
  digitalWrite (ledPin4, LOW);  
  delay(500);
}
