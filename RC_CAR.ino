#include <IRremote.hpp>
#define IR_PIN 2
#define forward_button 64
#define reverse_button 25
#define right_button 67
#define left_button 68
#define enA 3
#define enB 11
#define inA1 13
#define inA2 9
#define inB1 10
#define inB2 12
#define trigPin 8
#define echoPin 7
#define accelarate 70
#define deccelarate 21

int speed = 0;
long t0 = 0;

void setup() {
Serial.begin(9600);
IrReceiver.begin(IR_PIN);

pinMode(enB,OUTPUT);
pinMode(inB1,OUTPUT);
pinMode(inB2,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(inA1,OUTPUT);
pinMode(inA2,OUTPUT);

digitalWrite(inA1,LOW);
digitalWrite(inA2,LOW);
digitalWrite(inB1,LOW);
digitalWrite(inB2,LOW);

}

void loop() {
if(IrReceiver.decode()){
  t0 = millis();
  IrReceiver.resume();
  Serial.print(speed);
  switch(IrReceiver.decodedIRData.command){
    case forward_button:
      go_forward();
      break;
    case reverse_button:
      go_backwards();
      break;
    case right_button:
      go_right();
      break;
    case left_button:
      go_left();
      break;
    case accelarate:
      speed=constrain(speed+5,0,255);
      break;
    case deccelarate:
      speed=constrain(speed-5,0,255);
      break;
    default:
      break;
    }
  }
  if(millis()-t0> 200){
    turnOff();
  }
  // if(getValue()<5){
  //   turnOff();
  // }
}

void go_forward(){
    
  analogWrite(enA,speed);
  analogWrite(enB,speed);

  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
}

void go_backwards(){

  analogWrite(enA,speed);
  analogWrite(enB,speed);

  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
}

void go_right(){
  analogWrite(enA,speed);
  analogWrite(enB,speed);

  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
}

void go_left(){
  analogWrite(enA,speed);
  analogWrite(enB,speed);

  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
}

void turnOff(){
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
}

// long getValue(){
//   digitalWrite(trigPin,LOW);
//   delayMicroseconds(10);
//   digitalWrite(trigPin,HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin,LOW);
//   long value=pulseIn(echoPin,HIGH);
//   if (value == 0) 
//     return 9999;
//   else
//     return (value/2)/29.1;
// }
