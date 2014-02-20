// シフトレジスタを2つ繋いで順番に点灯
// http://hadatti.wordpress.com/2012/02/23/74hc595%E3%82%B7%E3%83%95%E3%83%88%E3%83%AC%E3%82%B8%E3%82%B9%E3%82%BF%E3%80%80%E5%88%9D%E5%BF%83%E3%81%AB%E6%88%BB%E3%81%A3%E3%81%A6%E5%AE%9F%E9%A8%93%EF%BC%88%EF%BC%91%EF%BC%89/

// Pin connected to ST_CP of 74HC595
// このPINをHIGHにするとそれまでのデータが出力される
int latchPin = 8;
int latchPin2 = 2;

// Pin connected to SH_CP of 74hc595
int clockPin = 12;
int clockPin2 = 5;

// Pin connected to DS of 74HC595
int dataPin = 11;
int dataPin2 = 4;

int a = 0b00000001;

void setup(){
  // set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
}

void loop(){
  // count from 0 to 255 and display the number
  // on the LEDs
  for(int numberToDisplay = 0; numberToDisplay < 16; numberToDisplay++){
    // take the latchPin low so
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    digitalWrite(latchPin2, LOW);

    int aa = a << numberToDisplay;
//    int aa = 0b11111111;
    int b  = aa >> 8;
    
    // shift out the bits:
//    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
    shiftOut(dataPin, clockPin, MSBFIRST, b);    // 上位データを送信
    shiftOut(dataPin, clockPin, MSBFIRST, aa);   // 下位データを送信
    shiftOut(dataPin2, clockPin2, MSBFIRST, b);    // 上位データを送信
    shiftOut(dataPin2, clockPin2, MSBFIRST, aa);   // 下位データを送信
    
    // take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin2, HIGH);
    // pause before next value:
    delay(1000);
  }
}
