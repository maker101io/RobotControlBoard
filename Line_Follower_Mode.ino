//Motor A
int motorA1 = 2;
int motorA2 = 4;
int motorAenb = 3;

//Motor B
int motorB1 = 10;
int motorB2 = 11;
int motorBenb = 9;

//IR sensor
#define IRsensor 12

void setup()
{
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorAenb, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBenb, OUTPUT);
  pinMode(IRsensor, INPUT);
}

void loop()
{
  int IRvalue = digitalRead(IRsensor);
  if(IRvalue == HIGH)
  {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    analogWrite(motorAenb, 90);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    analogWrite(motorBenb, 110);
  }
  else
  {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    analogWrite(motorAenb, 90);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(motorBenb, 110);
  }
  
  Serial.println(IRvalue);
}
