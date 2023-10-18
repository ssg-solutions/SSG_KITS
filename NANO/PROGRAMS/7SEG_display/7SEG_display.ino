//connect D2,D3,D4 & D5 to SEVEN SEGMENT DISPLAY A,B,C & D respectively
int inputs[4] = {2,3,4,5}; // A,B,C,D inputs
byte BCD[16][4] ={{0,0,0,0},
{1,0,0,0},
{0,1,0,0},
{1,1,0,0},
{0,0,1,0},
{1,0,1,0},
{0,1,1,0},
{1,1,1,0},
{0,0,0,1},
{1,0,0,1},
{0,1,0,1},
{1,1,0,1},
{0,0,1,1},
{1,0,1,1},
{0,1,1,1},
{1,1,1,1}}; //BCD code
int number = 0; //which number in BCD code do you want to send

void setup() {
for(int a = 0; a < 4; a++){
pinMode(inputs[a], OUTPUT);} //set outputs
}

void loop() {

while(number < 10)
{
for(int c = 0; c < 4; c++)
{
digitalWrite(inputs[c], BCD[number][c]);

}

number++;
delay(500);
}
number = 0;

}
