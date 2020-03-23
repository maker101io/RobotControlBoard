#include <Servo.h>

Servo myservo;

//Motor A
int motorA1 = 2;
int motorA2 = 4;
int motorAenb = 3;
#define motorArpm 100 //Any value between 0 and 255

//Motor B
int motorB1 = 10;
int motorB2 = 11;
int motorBenb = 9;
#define motorBrpm 110 //Any value between 0 and 255


void setup(){
  myservo.attach(5);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorAenb, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBenb, OUTPUT);

  analogWrite(motorAenb, 0);
  analogWrite(motorBenb, 0);
  myservo.write(70);
  delay(5000);
  myservo.write(120);
}

void loop(){
  myservo.write(70);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorAenb, motorArpm);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBenb, motorBrpm);
  delay(1000);

  analogWrite(motorAenb, 0);
  analogWrite(motorBenb, 0);
  delay(1000);
  
  myservo.write(120);
  delay(500);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(motorAenb, motorArpm);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBenb, motorBrpm);
  delay(1000);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(motorAenb, motorArpm);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(motorBenb, motorBrpm);
  delay(1000);
  analogWrite(motorAenb, 0);
  analogWrite(motorBenb, 0);
  myservo.write(70);
  delay(1000);
}
