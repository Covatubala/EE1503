/*
 姓名：任子杭
 学号：521030910282
 任课老师：孟桂娥
 */#include"Timer.h"
const int time3s=150;
int state=0;
//0:锁定；1：开锁；2：开锁放水
int Time3scounter=0;
int buttonstate=0,butcounter_steasdf_steasdf_steasdf_steasdf=0;
byte button1=HIGH,button2=HIGH;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PUSH1,INPUT_PULLUP);
  pinMode(PUSH2,INPUT_PULLUP);
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  

  SetTimer(isrTimer,20);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(Time3scounter>=time3s&&state==0)//3s后解锁
  {
    state=1;
    Time3scounter=0;
  }
  if(Time3scounter>=time3s&&state==1)//3s不放水，自动锁定
  {
    state=0;
    Time3scounter=0;
  }
  if(buttonstate==2)//PUSH2被按一次，此时应切换为放水
  {
    state=2;
  }
  if(buttonstate==4)//PUSH2被按两次，此时应切换为锁定
  {
    state=0;
    buttonstate=0;
  }


  switch(state)
  {
    case 0://锁定状态
    digitalWrite(RED_LED,HIGH);
    digitalWrite(GREEN_LED,LOW);
    break;
    case 1://解锁
    digitalWrite(RED_LED,LOW);
    break;
    case 2://放水状态
    digitalWrite(GREEN_LED,HIGH);
    break;
    default:break;
  }
}

void isrTimer()
{
  if(state==1&&digitalRead(PUSH2)==HIGH) Time3scounter++;//开锁状态且不是放水中
  unlock();
  water();
}

void unlock()
{
  button1=digitalRead(PUSH1);
  if(state==0){//锁定的时候
  if(button1==LOW)//长按PUSH1
  {
    Time3scounter++;
  }
  else//若中途抬起则清零
  {
    Time3scounter=0;
  }
  }
}


void water()
{
  button2=digitalRead(PUSH2);
  if(state==1&&buttonstate==0&&button2==LOW){
    buttonstate++;
  }
  if(state==1&&buttonstate==1&&button2==HIGH){
    buttonstate++;
  }//按下然后抬起作为一次动作,此时放水
  if(state==2&&buttonstate==2&&button2==LOW){
    buttonstate++;
  }
  if(state==2&&buttonstate==3&&button2==HIGH){
    buttonstate++;
  }//此时停止放水
  
}
