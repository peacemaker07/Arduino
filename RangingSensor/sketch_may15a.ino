/*
  距測センサ
  http://www.geocities.jp/zattouka/GarageHouse/micon/Arduino/DMSU/DMSU.htm
*/

void setup(){
  Serial.begin(9600);
}

void loop(){
  int ans;
  
  ans = analogRead(0);
  Serial.println(ans);
  delay(500);
}
