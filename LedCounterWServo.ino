#include <Servo.h>
Servo myservo;  // create servo object to control a servo

// constants won't change. They're used here to set pin numbers:
const int upButtonPin = 5;  // the number of the pushbutton pin
const int downButtonPin = 6;
const int resetButtonPin = 7;
const int greenLedPin = 11;    // the number of the LED pin
const int yellowLedPin = 12; 
const int redLedPin = 13; 

// variables will change:
int buttonStateU = 0;  // variable for reading the pushbutton status
int buttonStateD = 0;
int buttonStateR = 0;

int counter = 0; // counter used to control servo

void setup() {
  // initialize the LED pin as an output:
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(upButtonPin, INPUT);
  pinMode(downButtonPin, INPUT);
  pinMode(resetButtonPin, INPUT);

   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateU = digitalRead(upButtonPin);
  buttonStateD = digitalRead(downButtonPin);
  buttonStateR = digitalRead(resetButtonPin);

  if (counter > 20) {
    // turn red on
    digitalWrite(redLedPin, HIGH);
  } else {
    // turn red off:
    digitalWrite(redLedPin, LOW);
  }

  if (counter > 80) {
    // turn yellow on
    digitalWrite(yellowLedPin, HIGH);
  } else {
    // turn yellow off:
    digitalWrite(yellowLedPin, LOW);
  }

  if (counter > 120) {
    // turn green on
    digitalWrite(greenLedPin, HIGH);
  } else {
    // turn green off:
    digitalWrite(greenLedPin, LOW);
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateU == HIGH) {
    // increase the counter
    if (counter < 180) {
      counter += 1;
      delay(5);
    }
  } 
  if (buttonStateD == HIGH) {
    // decrease the counter
    if (counter > 0) {
      counter -= 1;
      delay(5);
    }
  }
  if (buttonStateR == HIGH) {
    // reset the counter
    counter = 0;
  }

  myservo.write(150 - counter / 1.5); 
}
