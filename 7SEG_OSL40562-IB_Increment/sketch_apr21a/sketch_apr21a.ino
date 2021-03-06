/*
  OSL40562-IB
*/

int num = 0;
int n;

int val = 0;
const int BUTTON = 1;

const int anode_pins[] = {12, 8, 5, 3, 2, 11, 6};    //アノードに接続するピン
const int cathode_pins[] = {7, 9, 10, 13};         //カソードに接続するピン
const int number_of_anode_pins = sizeof(anode_pins) / sizeof(anode_pins[0]);
const int number_of_cathode_pins = sizeof(cathode_pins) / sizeof(cathode_pins[0]);

const int digits[] = {
  0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00100111,  // 7
  0b01111111,  // 8
  0b01101111,  // 9
};

// 1桁の数字(n)を表示する
void display_number(int n) {
  for(int i = 0; i < number_of_anode_pins; i++){
    digitalWrite(anode_pins[i], digits[n] & (1 << i) ? LOW : HIGH); 
  }
}

// アノードをすべてHIGHにする
void clear_segments(){
  for(int j = 0; j < number_of_anode_pins; j++){
    digitalWrite(anode_pins[j], HIGH);
  }
}

void display_numbers(int n){
  for(int i = 0; i < number_of_cathode_pins; i++){
    digitalWrite(cathode_pins[i], HIGH);
    display_number(n % 10); // 最後の一桁を表示する
    delay(5);
    clear_segments();
    digitalWrite(cathode_pins[i], LOW);
    n = n / 10;  // 10で割る
  }
}

// setup() は、最初に一度だけ実行される
void setup(){
  pinMode(BUTTON, INPUT);
  
  for(int i = 0; i < number_of_anode_pins; i++){
    pinMode(anode_pins[i], OUTPUT);    // anode_pinsを出力モード
  }
  for(int i = 0; i < number_of_cathode_pins; i++){
    pinMode(cathode_pins[i], OUTPUT);  // cathode_pinを出力モード
    digitalWrite(cathode_pins[i], HIGH);
  }
}

void loop(){

  val = analogRead(BUTTON);

  if(val > 0){
    num++;
  }
  if(num == 9999){
    num = 0;
  }

  display_numbers(num);
}
