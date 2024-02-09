
// step 1
  // digitalWrite(pinDirectionA, HIGH); 
  // digitalWrite(pinDirectionB, LOW); 

// step 2
  //  digitalWrite(pinDirectionA, HIGH); 
  // digitalWrite(pinDirectionB, HIGH); 

// step 3
  //  digitalWrite(pinDirectionA, LOW);
  // digitalWrite(pinDirectionB, HIGH);

// step 4
  //  digitalWrite(pinDirectionA, LOW); 
  // digitalWrite(pinDirectionB, LOW); 

#include <Stepper.h>
#define STEPS 200

const int pinDirectionA = 12; // DIR
const int pinDirectionB = 13; // DIR
const int pinBrakeA = 9;  // BRAKE
const int pinBrakeB = 8;  // BRAKE
const int pinSpeedA = 3;  // EN
const int pinSpeedB = 11; // EN

Stepper stepper(STEPS, pinDirectionA, pinDirectionB);
int stepCount = 0;         // number of steps the motor has taken

//-----------------------------------------------------------------------
void setup() 
{ 
  //establish motor brake pins
  pinMode(pinBrakeA, OUTPUT); //brake (disable) CH A
  pinMode(pinBrakeB, OUTPUT); //brake (disable) CH B

  digitalWrite(pinBrakeA, LOW); //brake (disable) CH A
  digitalWrite(pinBrakeB, LOW); //brake (disable) CH B

  //establish motor Enable pins
  pinMode(pinSpeedA, OUTPUT); //Enable
  pinMode(pinSpeedB, OUTPUT); //Enable

  digitalWrite(pinSpeedA, HIGH); //Enable
  digitalWrite(pinSpeedB, HIGH); //Enable

  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);

  Serial.begin(9600);

  pinMode(pinDirectionA, OUTPUT); 
  pinMode(pinDirectionB, OUTPUT); 
}

//-----------------------------------------------------------------------
void loop() 
{
  // step one revolution  in one direction:
  Serial.println("clockwise");
  stepper.step(100);
  delay(1000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  stepper.step(-100);
  delay(1000);
}