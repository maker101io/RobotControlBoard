//Motor A
int motorA1 = 2;
int motorA2 = 4;
int motorAenb = 3;
#define motorArpm 90 //Any value between 0 and 255

//Motor B
int motorB1 = 10;
int motorB2 = 11;
int motorBenb = 9;
#define motorBrpm 100 //Any value between 0 and 255

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
    analogWrite(motorAenb, 0);
    analogWrite(motorBenb, 0);
    delay(200);
    
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    analogWrite(motorAenb, motorArpm);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    analogWrite(motorBenb, motorBrpm);
    delay(1000);

    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(motorBenb, motorBrpm);
    delay(400);
  }
  
  else
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    analogWrite(motorAenb, motorArpm);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(motorBenb, motorBrpm);
  }
  
  Serial.println(IRvalue);
}
