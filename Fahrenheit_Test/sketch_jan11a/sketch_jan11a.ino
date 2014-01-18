/*
　【未完成。。。】
  LM35DZを用いた温度測定（0℃~100℃）
  シリアルモニターに摂氏で表示させる
*/
int    A_inPin = 0;    // アナログ入力ピン番号
float  A_val;          // アナログ入力値（0~203）
float  tempC = 0;      // 摂氏値（℃）

void setup(){
  // シリアル通信速度
  Serial.begin(9600);
}

void loop(){
  A_val = analogRead(A_inPin);
  tempC = ((5 * A_val) / 1024) * 100;
  
  Serial.println(tempC);
  delay(1000);
}
