#include <Servo.h>

//Servo setup
Servo servoForJack;
Servo servoForCampfire;

// Input pins
const int boatPin = 2;
const int ralphAndPiggyHillSpot = 3;
const int ralphAndPiggyCampfireSpot = 5;
const int pigHeadStake = 13;
const int glassesPin = 6;

// Output pins
const int hillLED = 7;
const int randPCampfireLEDs = 8;
const int pigHeadLED = 9;
const int fireLEDPin = 4;

// To track state change (WE MIGHT NOT USE WE WILL SEE)
int prevBoatState = LOW;
int prevRalphPiggyHillState = LOW;
int prevRalphPiggyCampfireState = LOW;
int prevPigHeadStake = LOW;
int prevGlassesState = LOW;

void setup() {
  Serial.begin(9600);

  //Attach the servos to a specific pin
  servoForJack.attach(11);
  servoForCampfire.attach(12);

  //setting up Inputs
  pinMode(boatPin, INPUT);
  pinMode(ralphAndPiggyHillSpot, INPUT);
  pinMode(ralphAndPiggyCampfireSpot, INPUT);
  pinMode(pigHeadStake, INPUT);
  pinMode(glassesPin, INPUT);

  //setting up Outputs
  pinMode(hillLED, OUTPUT);
  pinMode(randPCampfireLEDs, OUTPUT);
  pinMode(pigHeadLED, OUTPUT);
  pinMode(fireLEDPin, OUTPUT);

  servoForJack.write(0);
  servoForCampfire.write(0);
  digitalWrite(fireLEDPin, HIGH);
}

void loop() {
  //Boat moves
  if (digitalRead(boatPin) == HIGH){
    Serial.println("Boat placed: Fire goes out");
    digitalWrite(fireLEDPin, LOW); // Turn fire off
  }

  //------------------------------------------------------------------------------------------

  //Jack spins away when R and P placed on the spot halfway up the hill old lights out new lights in
  if (digitalRead(ralphAndPiggyHillSpot) == HIGH){
    //Serial.println("Ralph & Piggy placed: Flipping to Jack & Pig head");
    servoForJack.write(180);
    //digitalWrite(hillLED, LOW);
    //digitalWrite(randPCampfireLEDs, HIGH);
  }

  //------------------------------------------------------------------------------------------

  //Move R and P to the campfire, old lights out new lights on
  if (digitalRead(ralphAndPiggyCampfireSpot) == HIGH){
    //digitalWrite(randPCampfireLEDs, LOW);
    digitalWrite(pigHeadLED, HIGH);
  }

  //------------------------------------------------------------------------------------------

  //Move pigs head to stake, causes Jack to spin and hit piggy 
  if (digitalRead(pigHeadStake) == HIGH){
    //Serial.println("Pigs head placed: Flipping jack back around");
    servoForJack.write(0);
    servoForCampfire.write(180);
    digitalWrite(pigHeadLED, LOW);
  }

  //------------------------------------------------------------------------------------------

  //  Glasses reinserted – turn on LED fire
  if (digitalRead(glassesPin) == HIGH) {
    //Serial.println("Glasses reinserted: Fire reignites");
    digitalWrite(fireLEDPin, HIGH); // Turn fire on
  }


  /*
  // Im also setting up lights so that i can use the code later on. there isnt much to it yet
  digitalWrite(led, HIGH);
  digitalWrite(led, LOW);
  */
}
