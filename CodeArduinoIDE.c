/*
PROJECT: "Designing and building a mobile robot with a control system based on the Arduino development board"

~Mini-firetruck

*development board: Arduino Uno R3
**utilized Arduino IDE v1.8.9 (for Windows)
*/


boolean fire = false;
// defining a bool type variable

int MOTOR_L = 12;
// initializing left servo motor - pin 12

int MOTOR_R = 13;
// initializing right servo motor - pin 13

#define Left_S 2
// defining infrared sensors: left - pin 2

#define Forward_S 4
// defining infrared sensors: middle - pin 4

#define Down_S 5
// defining infrared sensors: down (proximity) - pin 5

#define Right_S 7
// defining infrared sensors: right - pin 7

#define Pump 8         //analogWrite to be used
// defining water pump - pin 8

int Left_V = 0;
int Forward_V = 0;
int Down_V = 0;
int Right_V = 0;
// initializing infrared sensors with default value (0)

void setup()
{
    pinMode(Left_S, INPUT);
    pinMode(Forward_S, INPUT);
    pinMode(Right_S, INPUT);

    pinMode(Down_S, INPUT);

    pinMode(Pump, OUTPUT);

    pinMode(MOTOR_L, OUTPUT);
    pinMode(MOTOR_R, OUTPUT);
}



void loop()
{
    //ActivateFireSensors();
    SearchForFire();
    ExtinguishFire();
}
// looping the custom created functions

/*
void ActivateFireSensors(){
    Left_V = digitalRead(Left_S);
    Forward_V = digitalRead(Forward_S);
    Right_V = digitalRead(Right_S);
    Down_V = digitalRead(Down_S);
}
*/


void SearchForFire(){
// initializing a function with no parameters, which returns no result/no value
if (digitalRead(Left_S) != 0 && digitalRead(Forward_S) != 0 && digitalRead(Right_S) != 0)

    {
    digitalWrite(MOTOR_L, LOW);
    digitalWrite(MOTOR_R, LOW);
    }

    else if (digitalRead(Left_S) == 0)
    {
    digitalWrite(MOTOR_L, LOW);
    digitalWrite(MOTOR_R, HIGH);
    }

    else if (digitalRead(Forward_S) == 0)
    {
    digitalWrite(MOTOR_L, HIGH);
    digitalWrite(MOTOR_R, HIGH);
    fire = true;
    }

    else if (digitalRead(Right_S) == 0)
    {
    digitalWrite(MOTOR_L, HIGH);
    digitalWrite(MOTOR_R, LOW);
    }
}

/*
void ExtinguishFire(){

    while(fire == true){

    //delay (500);

    digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, HIGH);

    if (digitalRead(Down_S) == 0)
    {
    digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
    digitalWrite(Pump, HIGH);
    }
    else {
    digitalWrite(Pump, LOW);
    fire=false;
    }
  }
}
*/


void ExtinguishFire() {
// initializing a function with no parameters, which returns no result/no value
    if (digitalRead(Down_S) == 0)
    {
    digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
    digitalWrite(Pump, HIGH);
    }
    else{
    digitalWrite(Pump, LOW);
    }
}
