#define LED_PIN09 9
#define LED_PIN10 10
#define LED_PIN11 11
#define LED_PIN12 12

int flag;

void setup(){
  pinMode(LED_PIN09, OUTPUT);
  pinMode(LED_PIN10, OUTPUT);
  pinMode(LED_PIN11, OUTPUT);
  pinMode(LED_PIN12, OUTPUT);
}

void loop(){
  LED_RL();
  LED_LR();
}

void LED_RL(){
  analogWrite(LED_PIN09, 255);
  delay(100);
  analogWrite(LED_PIN09, 128);
  analogWrite(LED_PIN10, 255);
  delay(100);
  analogWrite(LED_PIN09, 0);
  analogWrite(LED_PIN10, 128);
  analogWrite(LED_PIN11, 255);
  delay(100);
  analogWrite(LED_PIN10, 0);
  analogWrite(LED_PIN11, 128);
  analogWrite(LED_PIN12, 255);
  delay(100);
  analogWrite(LED_PIN11, 0);
  analogWrite(LED_PIN12, 128);
  delay(100);
  analogWrite(LED_PIN12, 0);
  delay(100);
}

void LED_LR(){
  analogWrite(LED_PIN12, 255);
  delay(100);
  analogWrite(LED_PIN12, 128);
  analogWrite(LED_PIN11, 255);
  delay(100);
  analogWrite(LED_PIN12, 0);
  analogWrite(LED_PIN11, 128);
  analogWrite(LED_PIN10, 255);
  delay(100);
  analogWrite(LED_PIN11, 0);
  analogWrite(LED_PIN10, 128);
  analogWrite(LED_PIN09, 255);
  delay(100);
  analogWrite(LED_PIN10, 0);
  analogWrite(LED_PIN09, 128);
  delay(100);
  analogWrite(LED_PIN09, 0);
  delay(100);
}
