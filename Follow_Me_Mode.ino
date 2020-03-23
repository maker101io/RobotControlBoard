
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

//Ultrasonic Sensor
const int trigPin = 6;
const int echoPin = 5;

//Define Variables
long duration;
int distance;

void setup(){
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorAenb, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(motorBenb, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin , LOW);

  duration = pulseIn(echoPin , HIGH);
  distance = (duration/2) / 28.5;

  if(distance < 5)
  {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    analogWrite(motorAenb, motorArpm);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    analogWrite(motorBenb, motorBrpm);
  }
  
  if(distance > 5 && distance < 10)
  {
    analogWrite(motorAenb, 0);
    analogWrite(motorBenb, 0);
  }

  if(distance > 10 && distance < 20){
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    analogWrite(motorAenb, motorArpm);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(motorBenb, motorBrpm);
  }
  
  if(distance > 20)
  {
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    analogWrite(motorBenb, motorBrpm);
  }
}
