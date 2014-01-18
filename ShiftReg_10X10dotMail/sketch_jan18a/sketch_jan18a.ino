// シフトレジスタを2つ繋いで点灯＋10×10マトリクス[Mailアイコン]
// http://hadatti.wordpress.com/2012/02/23/74hc595%E3%82%B7%E3%83%95%E3%83%88%E3%83%AC%E3%82%B8%E3%82%B9%E3%82%BF%E3%80%80%E5%88%9D%E5%BF%83%E3%81%AB%E6%88%BB%E3%81%A3%E3%81%A6%E5%AE%9F%E9%A8%93%EF%BC%88%EF%BC%91%EF%BC%89/

// Pin connected to ST_CP of 74HC595
// このPINをHIGHにするとそれまでのデータが出力される
int latchPin  = 8;
int latchPin2 = 2;
// Pin connected to SH_CP of 74hc595
int clockPin  = 12;
int clockPin2 = 6;
// Pin connected to DS of 74HC595
int dataPin  = 11;
int dataPin2 = 5;

int a = 0b00000001;

void setup(){
  // set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  // DotLED
  pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
}

void loop(){
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00000001);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00000000);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00000010);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b01111110);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00000100);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b01111110);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00001000);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b01111110);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00010000);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b01100110);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00100000);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b01011010);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b01000000);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00111100);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b10000000);    // 上位データを送信
  shiftOut(dataPin2, clockPin2, MSBFIRST, 0b00000000);    // 下位データを送信
  digitalWrite(latchPin2, HIGH);

}
