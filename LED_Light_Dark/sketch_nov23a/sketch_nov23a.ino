/*
  LEDがだんだん明るくなる、暗くなる
*/
#define LED_PIN9 9
#define LED_PIN10 10

void setup(){
  pinMode(LED_PIN9, OUTPUT);
  pinMode(LED_PIN10, OUTPUT);
}

void loop(){
  int i;

  // test  
  //だんだん光る
  for(i = 0; i < 256; i++){
    analogWrite(LED_PIN9, i);
    analogWrite(LED_PIN10, 255-i);
    delay(10);
  }
  //だんだん消える
  for(i = 255; i > 0; i--){
    analogWrite(LED_PIN9, i);
    analogWrite(LED_PIN10, 255-i);
    delay(10);
  }
}
