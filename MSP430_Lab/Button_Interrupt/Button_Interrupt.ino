/*
  姓名：任子杭
  学号：521030910282
  任课老师姓名：孟桂娥
*/

volatile int state = HIGH;
volatile int flag = LOW;
int count = 0;

void setup(){
  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, state);
  pinMode(PUSH2, INPUT_PULLUP);
  attachInterrupt(PUSH2, blink, FALLING);
}

void loop(){
  if (flag) {
    digitalWrite(GREEN_LED, state);
    count++;
    Serial.println(count);
    flag= LOW;
  }
}

void blink(){
  state=!state;
  flag = HIGH;
}
