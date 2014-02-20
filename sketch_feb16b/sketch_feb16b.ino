// Pin connected to ST_CP of 74HC595
// このPINをHIGHにするとそれまでのデータが出力される
int latchPin = 8;

// Pin connected to SH_CP of 74hc595
int clockPin = 12;

// Pin connected to DS of 74HC595
int dataPin = 11;

int a = 0b00000001;
int led_sec;
int led_s10;
int led_mm;
int led_hh;

const int digits[] = {
  0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00100111,  // 7
  0b01111111,  // 8
  0b01101111,  // 9
};

void setup(){
  // set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  led_sec = 0;
  led_s10 = 0;
  led_mm  = 0;
  led_hh  = 0;
}

void loop(){
  int shift_out1;
  int shift_out2;
  int shift_out3;
  int shift_out4;

  shift_out1 = 0b0000001111111111 >> (10 - led_sec);
  shift_out2 = (shift_out1 >> 8) | ((0b111111 >> (6 - led_s10)) << 2);
  shift_out3 = digits[led_mm];
  shift_out4 = 0b00111111;

  // count from 0 to 255 and display the number
  // on the LEDs
  digitalWrite(latchPin, LOW);

  // shift out the bits:
  shiftOut(dataPin, clockPin, MSBFIRST, shift_out4);
  shiftOut(dataPin, clockPin, MSBFIRST, shift_out3);
  shiftOut(dataPin, clockPin, MSBFIRST, shift_out2);
  shiftOut(dataPin, clockPin, MSBFIRST, shift_out1);
    
  // take the latch pin high so the LEDs will light up:
  digitalWrite(latchPin, HIGH);
  // pause before next value:
  delay(1000);

  led_sec++;
  
  if(led_sec >= 10){
    led_sec = 0; 
    led_s10++; 
  }
  if(led_s10 >= 6){
    led_s10 = 0;
    led_mm++;
  }
  if(led_mm >= 60){
    led_mm = 0;
    led_hh++;
  }
  if(led_hh >= 24){
    led_hh = 0; 
  }
}
