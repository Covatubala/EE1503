/*
  姓名：任子杭
  学号：521030910282
  任课老师姓名：孟桂娥
*/

#include "Timer.h"

volatile unsigned int count = 0;

void setup() {
  Serial.begin(9600);

  SetTimer(isrTimer, 20);

}

void loop() {
  Serial.println(count);
  delay(1);
  
}

void isrTimer(void){
  count++;
}
