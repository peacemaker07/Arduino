// pinを宣言
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
const int cathode_pin12 = 13;

// 初期設定
void setup(){
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
  pinMode(cathode_pin12, OUTPUT);
}

// ループ
void loop(){
  digitalWrite(cathode_pin06, HIGH);
  digitalWrite(cathode_pin08, HIGH);
  digitalWrite(cathode_pin09, HIGH);
  digitalWrite(cathode_pin12, HIGH);
  disp00();
  delay(500);  
  disp01();
  delay(500);  
  disp02();
  delay(500);  
  disp03();
  delay(500);  
  disp04();
  delay(500);  
  disp05();
  delay(500);  
  disp06();
  delay(500);  
  disp07();
  delay(500);  
  disp08();
  delay(500);  
  disp09();
  delay(500);  
}

void disp00(){
  // 0
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, LOW);
}

void disp01(){
  // 1
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, HIGH);
}

void disp02(){
  // 2
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, HIGH);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, LOW);
}

void disp03(){
  // 3
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, HIGH);
  digitalWrite(anode_pin11, LOW);
}

void disp04(){
  // 4
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, HIGH);
}

void disp05(){
  // 5
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, LOW);
}

void disp06(){
  // 6
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, HIGH);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, LOW);
}

void disp07(){
  // 7
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, HIGH);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, HIGH);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, LOW);
}

void disp08(){
  // 8
  digitalWrite(anode_pin01, LOW);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, LOW);
}

void disp09(){
  // 9
  digitalWrite(anode_pin01, HIGH);
  digitalWrite(anode_pin02, LOW);
  digitalWrite(anode_pin03, HIGH);
  digitalWrite(anode_pin04, LOW);
  digitalWrite(anode_pin05, LOW);
  digitalWrite(anode_pin07, LOW);
  digitalWrite(anode_pin10, LOW);
  digitalWrite(anode_pin11, LOW);
}
