/*
  測距センサ
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
  
  float volts = analogRead(0)*0.0048828125; 
  float distance = 65 * pow(volts, -1.10);
  Serial.println(distance);
  delay(100);
}
