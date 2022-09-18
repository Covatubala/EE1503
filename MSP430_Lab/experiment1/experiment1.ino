/*
 姓名：任子杭
 学号：521030910282
 任课老师：孟桂娥
 
 */
#include"Timer.h"
int buttonstate=HIGH;
byte ledstate=LOW;
int Flag=0;
//用来确定灯状态
const int ti4sCouter_stesrt=100;
//以4s为周期
const int ti200msCouter_stesrt=5;
//以200ms为周期
int Couter_stesrt=0;//用来计时

void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH2,INPUT_PULLUP);
  pinMode(RED_LED,OUTPUT);

  SetTimer(isrTimer,20);

}

void loop() {
 
  if(Flag==1&&Couter_stesrt>=ti200msCouter_stesrt){
    //短闪状态
    digitalWrite(RED_LED,!ledstate);
    ledstate^=1;
    Couter_stesrt=0;
  }

  if(Flag==0&&Couter_stesrt>=ti4sCouter_stesrt){
    //长闪状态
    digitalWrite(RED_LED,!ledstate);
    ledstate^=1;
    Couter_stesrt=0;
  }
}


void isrTimer()
{
  buttonstate=digitalRead(PUSH2);
  if(buttonstate==LOW)
  //若按下，则短闪
  {
    Flag=1;
    Couter_stesrt++;
    //计时器增加
  }
  if(buttonstate==HIGH)
  //抬起，则长闪
  {
    Flag=0;
    Couter_stesrt++;
  }
}
