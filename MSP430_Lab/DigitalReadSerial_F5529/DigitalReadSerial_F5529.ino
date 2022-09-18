/*
  姓名：任子杭
  学号：521030910282
  任课老师姓名：孟桂娥
*/


int pushButton = PUSH2;

// setup 初始构造
void setup() {
  Serial.begin(19200);
  pinMode(pushButton, INPUT_PULLUP);
}

// loop 循环主函数
void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  delay(1);
}
