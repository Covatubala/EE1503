/*
  姓名：任子杭
  学号：521030910282
  任课老师姓名：孟桂娥
*/

#define LED RED_LED
  
// setup 初始构造
void setup() {                

  pinMode(LED, OUTPUT);     
}

// loop 循环主函数
void loop() {
  digitalWrite(LED, HIGH);   
  delay(4000);               
  digitalWrite(LED, LOW);    
  delay(4000);       
  digitalWrite(LED, HIGH);   
  delay(200);               
  digitalWrite(LED, LOW);    
  delay(200);         
}
