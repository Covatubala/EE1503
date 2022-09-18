/*
  姓名：任子杭
  学号：521030910282
  任课老师姓名：孟桂娥
*/

const int buttonPin = PUSH2;     
const int ledPin =  GREEN_LED;   


int buttonState = 0;        

// setup 初始构造
void setup() {
  
  pinMode(ledPin, OUTPUT);      
  
  pinMode(buttonPin, INPUT_PULLUP);     
}

// loop 循环主函数
void loop(){
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {     
    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    
    digitalWrite(ledPin, LOW); 
  }
}
