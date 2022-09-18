/*
  姓名：任子杭
  学号：521030910282
  任课老师姓名：孟桂娥
*/

#include "Timer.h"

volatile int state = HIGH;
volatile int flag = LOW;
int count = 0;

int buttonState = HIGH;
int lastButtonState = HIGH;

void setup(){
  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, state);
  pinMode(PUSH2, INPUT_PULLUP);
  SetTimer(isrTimer, 20);
}

void loop(){
  if (flag) {
    flag= LOW;
    digitalWrite(GREEN_LED, state);
    count++;
    Serial.println(count);
    
  }
}
void isrTimer(void){
  Push2_Dect();
}
void Push2_Dect(){
  buttonState = digitalRead(PUSH2);
  if (buttonState != lastButtonState){
    if(buttonState == LOW) {
      state = !state;
      flag = HIGH;
    }
  }
  lastButtonState = buttonState;
}
