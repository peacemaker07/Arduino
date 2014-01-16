int ir_out = 2;
int led = 9;

// エアコンオン（冷房、26度 微）
//unsigned intdata[] = {342,163,47,120,50,33,48,40,44,40,36,48,36,45,46,40,44,39,46,40,41,40,44,35,40,45,40,127,38,48,46,39,44,34,46,39,44,40,44,40,44,40,36,48,46,40,41,40,44,39,44,39,44,39,36,47,45,39,47,34,39,48,44,120,48,39,47,119,46,121,47,122,46,122,45,120,47,121,47,40,46,118,48,120,48,122,36,129,48,120,39,129,49,118,39,130,46,121,49,40,41,40,35,47,45,39,36,47,44,40,46,40,43,35,46,40,44,37,49,119,49,119,47,35,50,36,45,121,38,131,44,121,38,130,46,37,38,48,46,118,47,121,49,40,43,38,46,34,39,129,47,39,44,40,36,130,47,39,44,39,44,122,38,129,49,35,38,129,39,131,36,48,43,121,49,118,47,40,46,118,39,130,48,35,41,45,44,123,44,40,43,40,36,48,44,40,36,45,38,129,38,130,46,40,44,122,44,122,47,122,37,48,36,48,44,35,50,119,38,48,44,121,47,123,47,37,44,123,44,120,48,120,47,35,40,129,46,36,48,40,44,121,47,40,38,44,37,47,44,42,33,45,38,48,44,39,36,48,36,129,50,118,38,129,39,129,41,126,47,121,39,131,36,129,47,36,50,34,39,48,36,48,46,34,38,48,36,48,44,38,37,129,39,129,41,126,49,119,46,121,50,118,46,121,47,121,38,48,36,48,46,40,36,45,36,47,38,48,33,48,36,48,44,122,37,129,38,130,46,123,37,129,39,130,41,127,41,127,38,48,35,48,44,40,36,47,44,39,36,48,38,48,36,45,35,129,39,131,36,130,38,129,39,131,37,129,39,129,39,131,36,46,38,48,35,48,36,48,36,45,38,45,38,48,36,48,36,129,49,118,47,121,47,120,38,129,50,118,39,130,46,120,47,121,49,118,38,48,35,48,35,129,38,48,35,47,44,36,47,40,43,40,44,121,38,129,39,45,49,119,38,128,47,121,38,130,38,48,35,47,36,48,35,129,47,40,36,129,47,121,38,49,38,126,47,121,38,129,38,49,38,126,38,49,35,49,35,47,44,35,40,48,44,40,36,48,36,45,38,48,36,45,38,129,41,127,41,126,39,129,38,130,40,127,38,130,38,129,39,48,35,48,35,48,38,45,36,47,36,48,36,48,38,48,33,129,39,129,42,126,41,126,38,130,41,127,38,130,38,129,41};
 
// エアコンオフ
//unsigned int data[] = {347,158,53,114,53,28,55,28,56,28,56,26,57,35,49,26,57,26,57,26,57,26,57,26,57,28,56,115,53,34,49,27,56,28,55,28,55,26,56,28,55,28,56,26,57,28,56,26,58,34,48,26,57,26,57,28,56,26,57,28,56,26,57,115,53,35,48,117,51,115,53,115,53,116,52,115,52,115,53,28,55,115,52,115,53,115,53,115,53,115,53,117,50,117,51,116,52,115,52,28,56,28,55,26,57,28,55,29,54,28,56,26,57,28,56,29,54,28,56,116,52,115,52,28,55,28,56,116,52,115,53,115,53,115,52,28,56,28,55,115,53,115,52,28,55,28,55,28,55,115,53,28,55,29,55,116,52,28,56,28,55,116,52,115,52,29,55,115,53,115,53,27,55,116,52,115,53,28,55,115,53,115,53,28,55,29,55,116,52,28,55,26,57,28,55,28,55,29,55,116,52,116,52,28,55,115,53,114,53,115,53,28,55,28,55,28,56,116,52,28,55,115,53,116,52,28,55,116,52,117,51,116,53,28,55,115,53,34,48,28,55,116,52,28,55,28,55,26,57,28,56,28,55,28,55,35,48,28,56,116,52,115,52,116,52,116,53,115,53,115,52,116,52,115,53,28,55,28,56,28,56,28,55,28,55,28,55,28,55,28,55,116,52,116,52,116,53,115,52,115,53,115,53,115,52,115,52,29,55,28,56,28,55,28,55,28,55,29,55,28,55,29,55,116,52,115,53,116,52,115,53,115,53,115,52,115,53,115,53,27,56,29,55,28,56,28,55,28,55,28,56,28,56,28,55,116,52,115,53,116,52,115,52,115,53,119,49,115,53,115,52,26,57,28,55,26,57,28,56,29,55,28,55,28,55,29,54,117,50,115,52,116,52,116,53,115,53,115,52,115,53,115,53,115,52,115,53,28,55,28,56,28,55,28,56,115,52,28,55,28,56,29,55,116,52,116,52,116,53,115,52,28,56,115,52,116,53,28,55,28,56,28,56,28,56,28,56,115,52,116,52,28,55,115,53,115,53,115,53,115,52,115,53,27,56,28,56,28,56,28,55,29,55,26,57,28,55,28,56,26,57,28,56,115,53,115,52,116,51,115,52,117,51,116,53,115,53,115,52,28,55,29,55,29,55,28,56,28,56,28,55,28,55,28,55,115,53,115,53,117,51,115,52,115,53,117,50,115,53,115,52};
unsigned int data[] = {41,46,46,40,50,36,46,40,40,46,44,2526,348,170,40,132,40,47,45,40,40,46,40,132,40,47,39,46,40,46,39,46,135,470,362,417,414,451,385,412,453,392,401,416,433,398,415,444,388,3116,342,176,45,128,40,47,39,46,40,47,298,416,449,392,405,460,385,403,415,439,392,416,442,393,412,3871,342,176,40,133,51,35,40,46,40,46,40,132,126,392,412,452,392,473,386,392,398,416,436,396,416,446,386,416,415,512,319,459,386,402,415,439,392,473,386,392,412,452,392,402,456,392,398,416,415,416,415,};
 
// Apple TV再生ボタン
//unsigned int data[] = {905,445,57,57,54,164,58,164,58,164,58,54,58,163,58,164,58,164,58,164,57,164,58,164,58,57,55,57,54,57,55,57,55,164,58,164,58,164,58,164,58,164,58,164,58,57,55,164,58,57,55,164,58,164,58,164,58,164,58,57,54,57,54,164,58,56,58,3390,905,444,58,54,58,164,58,164,58,164,58,56,55,164,58,164,58,164,60,162,58,164,58,164,58,57,54,57,55,57,55,54,57,164,58,164,58,56,55,164,57,54,58,54,57,57,55,54,57,54,58,164,58,164,58,164,58,164,61,51,57,57,55,164,58,58,55};

int last = 0;
unsigned long us = micros();

// セットアップ
void setup(){
  pinMode(ir_out, OUTPUT);
  pinMode(led, OUTPUT);
}

// dateからリモコン信号を送信
void sendSignal(){
  int dataSize = sizeof(data) / sizeof(data[0]);
  for(int cnt = 0; cnt < dataSize; cnt++){
    unsigned long len = data[cnt] * 10;    //dataは10us単位でON/OFF時間を記録している
    unsigned long us = micros();
    
    do{
      digitalWrite(ir_out, 1 - (cnt & 1));  // cntが偶数なら赤外線ON、奇数ならのまま
      delayMicroseconds(8);                 // キャリア周波数38kHzでON/OFFするよう時間調整
      digitalWrite(ir_out, 0);
      delayMicroseconds(7);
    } while(long(us + len - micros()) > 0); // 送信時間に達するまでループ
  }
}

void loop(){
  digitalWrite(led, HIGH);
  sendSignal();
  digitalWrite(led, LOW);
  delay(3000);
}