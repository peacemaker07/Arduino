#define READ_PIN   7
#define LOW_STATE  0
#define HIGH_STATE 1
#define LED_PIN    9

void setup(){
  pinMode(READ_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(57600);
  Serial.print("Ready to receive");
  Serial.print("\n");  
}

void waitLow(){
  while(digitalRead(READ_PIN) == LOW){
    ; 
  }
}

int waitHigh(){
  unsigned long start = micros();
 
  while(digitalRead(READ_PIN) == HIGH){
    if(micros() - start > 5000000){
      return 1;
    }
  }
  return 0;
}

unsigned long now = micros();
unsigned long lastStateChangedMicros = micros();
int state = HIGH_STATE;

void loop(){
  if(state == LOW_STATE){
    digitalWrite(LED_PIN, LOW);
    waitLow();
  } else {
    int ret = waitHigh();
    if(ret == 1){
      Serial.print("\n");
      return; 
    }
    digitalWrite(LED_PIN, HIGH);
  }
  
  now = micros();
  Serial.print((now - lastStateChangedMicros) / 10, DEC);
  Serial.print(",");
  lastStateChangedMicros = now;
  if(state == HIGH_STATE){
    state = LOW_STATE;
  } else {
    state = HIGH_STATE;
  }
}
