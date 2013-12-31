const int anode_pin01 = 2;
const int anode_pin02 = 3;
const int anode_pin03 = 4;
const int anode_pin04 = 5;
const int anode_pin05 = 6;
const int anode_pin07 = 8;
const int anode_pin10 = 11;
const int anode_pin11 = 12;
const int cathode_pin06 = 7;
const int cathode_pin08 = 9;
const int cathode_pin09 = 10;
//const int cathode_pin12 = 13;

#define SPK_PIN 13

void setup() {
  pinMode(anode_pin01, OUTPUT);
  pinMode(anode_pin02, OUTPUT);
  pinMode(anode_pin03, OUTPUT);
  pinMode(anode_pin04, OUTPUT);
  pinMode(anode_pin05, OUTPUT);
  pinMode(anode_pin07, OUTPUT);
  pinMode(anode_pin10, OUTPUT);
  pinMode(anode_pin11, OUTPUT);
  pinMode(cathode_pin06, OUTPUT);
  pinMode(cathode_pin08, OUTPUT);
  pinMode(cathode_pin09, OUTPUT);
//  pinMode(cathode_pin12, OUTPUT);
  pinMode(SPK_PIN, OUTPUT);
}

void loop() {

  // スタート音
  tone(SPK_PIN, 800, 400);
  delay(600);
  tone(SPK_PIN, 800, 400);
  delay(600);
  tone(SPK_PIN, 800, 400);
  delay(600);
  tone(SPK_PIN, 1000, 1000);
  delay(500);


  //0
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //1
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, LOW);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //2
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //3
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //4
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, LOW);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //5
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //6
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //7
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //8
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
  //9
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, LOW);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, HIGH);
  digitalWrite(cathode_pin06, LOW);
  digitalWrite(cathode_pin08, LOW);
  digitalWrite(cathode_pin09, LOW);
//  digitalWrite(cathode_pin12, LOW);
  delay(500);
}
