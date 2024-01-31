
const int pinDirectionA = 12;
const int pinDirectionB = 13;
const int pinBrakeA = 9;
const int pinBrakeB = 8;
const int pinSpeedA = 3;
const int pinSpeedB = 11;

int delayValue = 3;
int nPhase = 0;
unsigned long nCurrentMillis = 0;
unsigned long nPreviousMillis = 0;
bool bWithBreak = true;
int nCurrentAngle = 0;    // 1° == 10
int nTargetAngle = 3600;  // 1° == 10
int nSens = 0;

//-----------------------------------------------------------------------
void setup() 
{
  //establish motor direction toggle pins
  pinMode(pinDirectionA, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  pinMode(pinDirectionB, OUTPUT); //CH B -- HIGH = forwards and LOW = backwards???
  
  //establish motor brake pins
  pinMode(pinBrakeA, OUTPUT); //brake (disable) CH A
  pinMode(pinBrakeB, OUTPUT); //brake (disable) CH B

  Serial.begin(9600);
}

//-----------------------------------------------------------------------
void loop() 
{
  nCurrentMillis = millis();

  int trimVal = analogRead(A5);

  if (trimVal < 400)
  {
    nSens = -1;
    delayValue = map(trimVal, 0, 400, 3, 100);
  } 
  else if (trimVal > 600)
  {
    nSens = +1;
    delayValue = map(trimVal, 600, 989, 100, 3);
  }
  else
  {
    delayValue = 999;
    nSens = 0;
  }

  Serial.println(delayValue);
  
  //delayValue = map(trimVal, 0, 1023, 100, 3);
  
  if ((nCurrentMillis - nPreviousMillis) >= delayValue)
  {
    nPreviousMillis = nCurrentMillis;

    if (nSens == 1)
    {
      Step(true);
      nCurrentAngle += 18;
    }
    else if (nSens == -1)
    {
      Step(false);
      nCurrentAngle -= 18;
    }
  }
  
  //delay(delayValue);
}

//-----------------------------------------------------------------------
void Step(bool bClockwiseDirection)
{
  if (bClockwiseDirection)
  {
    nPhase++;
    if (nPhase > 3)
    {
      nPhase = 0;
    }
  }
  else
  {
    nPhase--;
    if (nPhase < 0)
    {
      nPhase = 3;
    }
  }
  
  switch (nPhase)
  {
  case 0 :
    if (bWithBreak)
    {
      digitalWrite(pinBrakeA, LOW);  //ENABLE CH A
      digitalWrite(pinBrakeB, HIGH); //DISABLE CH B
    }
    digitalWrite(pinDirectionA, HIGH);   //Sets direction of CH A
    analogWrite(pinSpeedA, 255);   //Moves CH A
    break;
  case 1 :
    if (bWithBreak)
    {
      digitalWrite(pinBrakeA, HIGH);  //DISABLE CH A
      digitalWrite(pinBrakeB, LOW); //ENABLE CH B
    }
    digitalWrite(pinDirectionB, LOW);   //Sets direction of CH B
    analogWrite(pinSpeedB, 255);   //Moves CH B
    break;
  case 2 :
    if (bWithBreak)
    {
      digitalWrite(pinBrakeA, LOW);  //ENABLE CH A
      digitalWrite(pinBrakeB, HIGH); //DISABLE CH B
    }
    digitalWrite(pinDirectionA, LOW);   //Sets direction of CH A
    analogWrite(pinSpeedA, 255);   //Moves CH A
    break;
  case 3 :
    if (bWithBreak)
    {
      digitalWrite(pinBrakeA, HIGH);  //DISABLE CH A
      digitalWrite(pinBrakeB, LOW); //ENABLE CH B
    }
    digitalWrite(pinDirectionB, HIGH);   //Sets direction of CH B
    analogWrite(pinSpeedB, 255);   //Moves CH B
    break;
  }
}
