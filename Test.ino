#include <Servo.h>

const int led = 8;
const int switchOne = 4;

int switchOneVal;

Servo myservo; 


void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(switchOne, INPUT);

  myservo.attach(12); 
}

void loop() {
  switchOneVal = digitalRead(switchOne);
  Serial.println(switchOneVal);

  if (switchOneVal == 1){
    digitalWrite(led, HIGH);
    myservo.write(180); 
  }
  else{
    digitalWrite(led, LOW);
    myservo.write(0); 
  }
  
}
