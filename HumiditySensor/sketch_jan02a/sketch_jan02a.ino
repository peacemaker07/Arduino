// 湿度センサ
// http://forum.arduino.cc/index.php?topic=143815.0

int analogPin = 0;
int digitalPin = 2;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print("Analog: ");
  Serial.print(getValue());
  Serial.print(" Digital: ");
  Serial.println(digitalRead(digitalPin));
  delay(1000);
}

float getValue(){
  int val = 0;
  
  val = analogRead(analogPin);
  // need som calca to HR%
  return val;
}
