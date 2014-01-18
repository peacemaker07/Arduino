/*
  FullColorLED＋ボタン
    RGBごとにボタンがあり、おすとRGB値がカウントアップ
*/

int  val_GREEN = 0;
int  val_RED   = 0;
int  val_BULE  = 0;

#define BUTTON_RESET 6
#define BUTTON_GREEN 7
#define BUTTON_RED   8
#define BUTTON_BULE  9

#define LCD_GREEN 10
#define LCD_RED   11
#define LCD_BULE  12

void setup(){
  pinMode(BUTTON_RESET, INPUT);
  pinMode(BUTTON_GREEN, INPUT);
  pinMode(BUTTON_RED,   INPUT);
  pinMode(BUTTON_BULE,  INPUT);

  pinMode(LCD_GREEN, OUTPUT);
  pinMode(LCD_RED,   OUTPUT);
  pinMode(LCD_BULE,  OUTPUT);
  
  analogWrite(LCD_GREEN, 0);
  analogWrite(LCD_RED,   0);
  analogWrite(LCD_BULE,  0);

  Serial.begin(9600);
}

void loop(){
  int  val;
  
  // GREEN
  val = digitalRead(BUTTON_GREEN);
  if(val == HIGH){
    val_GREEN++;
  }
  if(val_GREEN == 255){
    val_GREEN = 0;
  }
  analogWrite(LCD_GREEN, val_GREEN);

  // RED
  val = digitalRead(BUTTON_RED);
  if(val == HIGH){
    val_RED++;
  }
  if(val_RED == 255){
    val_RED = 0;
  }
  analogWrite(LCD_RED, val_RED);

  // BULE
  val = digitalRead(BUTTON_BULE);
  if(val == HIGH){
    val_BULE++;
  }
  if(val_BULE == 255){
    val_BULE = 0;
  }
  analogWrite(LCD_BULE, val_BULE);

  // RESET
  val = digitalRead(BUTTON_RESET);
  if(val == HIGH){
    val_GREEN = 0; 
    val_RED   = 0; 
    val_BULE  = 0; 
  }

  Serial.print(val_GREEN);
  Serial.print("\n");
  Serial.print(val_RED);
  Serial.print("\n");
  Serial.print(val_BULE);
  Serial.print("\n");
}
