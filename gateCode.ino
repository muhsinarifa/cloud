#include <Servo.h>
#define LED1 2
#define LED2 3
Servo servo1;

int gate=90,p1=0,p2=0;

//gate
int trigPin1 = 5; 
int echoPin1 = 4;

int trigPin2 = 7;
int echoPin2 = 6;

//park 1
int trigPinP1 = 9;
int echoPinP1 = 8;

//park 2
int trigPinP2 = 11;
int echoPinP2 = 10;

long distance1;
long duration1;

long distance2;
long duration2;

long distanceP1;
long durationP1;

long distanceP2;
long durationP2;
 
void setup() 
{
 servo1.attach(12); 
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 pinMode(trigPinP1, OUTPUT);
 pinMode(echoPinP1, INPUT);
 pinMode(trigPinP2, OUTPUT);
 pinMode(echoPinP2, INPUT);
}
 
void loop() {
  servo1.write(gate);
  OUT1();
  OUT2();
  Park1();
  Park2();

  if(distance1 <= 10){
    if(gate==0){
       gate=90;
    }
    else{
       gate=0;
    } 
    delay(500);    
  } 

  if(distance2 <= 10){
    if(gate==0){
       gate=90;
    }
    else{
       gate=0;
    }
    delay(500);
  }

  if(distanceP1 <= 10){
    p1=1;
    digitalWrite(LED1, LOW);    
  
  }
  else{
    p1=0;
    digitalWrite(LED1, HIGH);

  }

  if(distanceP2 <= 10){
    p2=1;
    digitalWrite(LED2, LOW);
  }
  else{
    p2=0;
    digitalWrite(LED2, HIGH);
  }  

}
 
void OUT1(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  } 

void OUT2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;
  } 

void Park1(){
  digitalWrite(trigPinP1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinP1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinP1, LOW);
  durationP1 = pulseIn(echoPinP1, HIGH);
  distanceP1 = durationP1*0.034/2;
  } 

void Park2(){
  digitalWrite(trigPinP2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinP2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinP2, LOW);
  durationP2 = pulseIn(echoPinP2, HIGH);
  distanceP2 = durationP2*0.034/2;
  } 