/*

This code is rough and will have to be changed later on. I dont know what Thomas has already done so
if our work overlaps well just take the parts from each we need and like.



*/
#include <Servo.h>

Servo servoForCampfire;
Servo servoForJack;

const int buttonPinCampfire = 2;
const int buttonPinjack = 3;
const int led = 4;

bool jackDirSwitch = 0;

void setup() {
  //Attach the servos to a specific pin
  servoForCampfire.attach(9);
  servoForJack.attach(10);

  //Sets the inputs
  pinMode(buttonPinCampfire, INPUT);
  pinMode(buttonPinjack, INPUT);

  //setting up lights to work
  pinMode(led, OUTPUT);
}

void loop() {
  // If either input is read as high, their respective servos will rotate. 
  if (digitalRead(buttonPinCampfire) == HIGH){
    servoForCampfire.write(180);
  }

  //Jack requires special behavior, so here he turns around twice using something like a switch
  if (digitalRead(buttonPinjack) == HIGH && jackDirSwitch == 0){
    servoForJack.write(180);
    jackDirSwitch = 1
  }
  if (digitalRead(buttonPinjack) == HIGH && jackDirSwitch == 1){
    servoForJack.write(-180);
    jackDirSwitch = 0
  }

  // Im also setting up lights so that i can use the code later on. there isnt much to it yet
  digitalWrite(led, HIGH);
  digitalWrite(led, LOW);
}
