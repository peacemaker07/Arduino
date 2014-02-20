/*
  音量分 LEDが点灯
  http://arms22.blog91.fc2.com/blog-entry-284.html
*/

int  levelLeds[] = {
  2,3,4,5,6,7,8,9 };
  
void setup(){
  for(int i = 0; i < 8; i++){
    pinMode(levelLeds[i], OUTPUT);
    digitalWrite(levelLeds[i], LOW);
  }
  Serial.begin(9600);
}

int ecmPin = 0;

void loop(){
  static int lasEcmLevel = 0;
  int input = analogRead(ecmPin);
  
  Serial.print(input);
  Serial.print(", ");
  
  if(input > 512){
    input = abs(input - 512);
  }
  else {
    input = 0;
  }
  
  Serial.println(input);
  
  int ecmLevel = map(input, 80, 380, 0, 8);
  
//  if(){
//    lasEcmLevel++; 
//  }
//  else if(ecmLevel < lasEcmLevel){
//    lasEcmLevel--;
//  }
  lasEcmLevel = ecmLevel;
  
  int pos;
  for(pos = 0; pos < lasEcmLevel; pos++){
    digitalWrite(levelLeds[pos], HIGH);
  }
  
  for(; pos < 8; pos++){
    digitalWrite(levelLeds[pos], LOW);
  }
  
  delay(5);
}
