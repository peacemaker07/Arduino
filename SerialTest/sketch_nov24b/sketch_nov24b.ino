/*
  シリアルモニタのテスト
*/
#define SENSOR 0

void setup(){
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
}

void loop(){
  int i;
  i = analogRead(SENSOR); //0 - 1023
  Serial.print(i, DEC);
  Serial.print("\n");
  delay(1000);
}
