#include <Servo.h>

Servo servoForJack;

const int ralphAndPiggyHillSpot = 3;
const int ralphAndPiggyCampfireSpot = 3;
const int pigHeadStake = 3;

const int hillLED = 4;
const int randPCampfireLEDs = 5;
const int pigHeadLED = 6;

bool jackDirSwitch = 0;

void setup() {
  //Attach the servos to a specific pin
  servoForJack.attach(10);

 
  //setting up lights to work
  pinMode(hillLED, OUTPUT);
  pinMode(randPCampfireLEDs, OUTPUT);
  pinMode(pigHeadLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  //------------------------------------------------------------------------------------------

  //Jack spins away when R and P placed on the spot halfway up the hill old lights out new lights in
  if (digitalRead(ralphAndPiggyHillSpot) == HIGH && jackDirSwitch == 0){
    servoForJack.write(180);
    digitalWrite(hillLED, LOW);
    digitalWrite(randPCampfireLEDs, HIGH);
    jackDirSwitch = 1;
  }

  //------------------------------------------------------------------------------------------

  //Move R and P to the campfire, old lights out new lights on
  if (digitalRead(ralphAndPiggyHillSpot) == HIGH){
    digitalWrite(randPCampfireLEDs, LOW);
    digitalWrite(pigHeadLED, HIGH);
  }

  //------------------------------------------------------------------------------------------

  //Move pigs head to stake, causes Jack to spin and hit piggy (i believe the rest is to be made by thomas)
  if (digitalRead(pigHeadStake) == HIGH && jackDirSwitch == 1){
    servoForJack.write(0);
    digitalWrite(pigHeadLED, LOW);
    jackDirSwitch = 0;
  }




  /*
  // Im also setting up lights so that i can use the code later on. there isnt much to it yet
  digitalWrite(led, HIGH);
  digitalWrite(led, LOW);
  */
}
