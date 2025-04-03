              //for normal button pressed

/*
const int buttonPin = 1; //choose a buttonPin
int buttonVal = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonVal = digitalRead(buttonPin);
  
  if (buttonVal == LOW){
    //default action when button is not pressed
    Serial.println("pressed") //test for button
  } else {
    //action when button is pressed
    Serial.println("pressed") //test for button
  }
}
*/



             //for state change detection

/* 
const int buttonPin = 2;
int buttonState = 0;
int previousButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}
void loop(){
  buttonState = digitalRead(buttonPin);
  if (buttonState != previousButtonState) {
    if (buttonState = HIGH) {
      Serial.println("button pressed");
    } else {
      Serial. println("button released");
    }
  }
previousButtonState = buttonState;

} 
*/

          //for Servos

/* 
Servo myservo; //servo variable
const int buttonPin = 2; //select buttonPin

void setup() {
  myservo.attach(9); //servo is attatched to pin 9
  pinMode(buttonPin, INPUT);
}

void loop() {
  if(digitalRead(buttonPin) == HIGH){
    myservo.write(180); //decides angle servo turns (0-180)
  } else {
    myservo.write(0);
  }
}








