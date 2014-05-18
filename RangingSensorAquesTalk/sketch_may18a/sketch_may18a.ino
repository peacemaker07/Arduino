/*
  測距センサ
  http://www.geocities.jp/zattouka/GarageHouse/micon/Arduino/DMSU/DMSU.htm
  Hello Talk
  http://blog-yama.a-quest.com/?eid=970150
*/

#include <Wire.h>                // I2C通信用ライブラリ

// PIN
#define RANG_PIN_L 0             // 測距センサ左側
#define RANG_PIN_R 1             // 測距センサ右側

// 変数
int    PassL;                    // 通過判定用　左
int    PassR;                    // 通過判定用　右

void setup(){
  // ピンモード
  pinMode(RANG_PIN_L, INPUT);
  pinMode(RANG_PIN_R, INPUT);
 
  // I2C通信 初期化
  Wire.begin();
 
  // シリアル通信開始
  Serial.begin(9600);
  
  initGlobal();
  
  while(AquesTalk_IsBusy());      // Ready待ち
  AquesTalk_Synthe("#J");         // 「ポン！」チャイム音出力
}

// グローバル変数初期化
void initGlobal(){
  PassL = 0;
  PassR = 0;
}

void loop(){
  float    voltsL;              // 左側のセンサ　電圧
  float    voltsR;              // 右側のセンサ　電圧
  float    distanceL;           // 左側のセンサ　距離
  float    distanceR;           // 右側のセンサ　距離
  
  int      tmpPassL;            // 通過判定用　左
  int      tmpPassR;            // 通過判定用　右
  int      passflg;             // 通過フラグ（0:未通過、1:左→右、2:右→左、9:同時）


  // 距離を測定
  // 左側
  voltsL = analogRead(RANG_PIN_L) * 0.0048828125;
  distanceL = getDistance(voltsL);
//  Serial.println("LLLLLLLLLLLLL");
//  Serial.println(voltsL);
//  Serial.println(distanceL);

  // 右側
  voltsR = analogRead(RANG_PIN_R) * 0.0048828125;
  distanceR = getDistance(voltsR);
//  Serial.println("RRRRRRRRRRRRR");
//  Serial.println(voltsR);
//  Serial.println(distanceR);
  
  // 人が通ったか判定
  tmpPassR = getPass(distanceR);
  tmpPassL = getPass(distanceL);
  
  passflg = 0;                      // 初期化
  // 通過し始めたか判定
  if((PassL == 0) && (PassR == 0)){
    if(tmpPassR == 1){
      PassR = 1; 
    }
    else if(tmpPassL == 1){
      PassL = 1; 
    }
  // 左、右同時
  } else if((tmpPassL == 1) && (tmpPassR == 1)){
    passflg = 9;
    initGlobal();
  // 左→右
  } else if((PassL == 1) && (tmpPassR == 1)){
    passflg = 1;                    // 通過
    initGlobal();
  // 右→左
  } else if((PassR == 1) && (tmpPassL == 1)){
    passflg = 2;                    // 通過
    initGlobal();
  }

  // 通過した方向により音声を出す
  // 同時
  if(passflg == 9){
    if(!AquesTalk_IsBusy()){
      AquesTalk_Synthe("hanarete kudasai.");
    }
  }
  // 左→右
  else if(passflg == 1){
    if(!AquesTalk_IsBusy()){
      AquesTalk_Synthe("arigatou matakitene.");
    }
  }
  // 右→左
  else if(passflg == 2){
    if(!AquesTalk_IsBusy()){
      AquesTalk_Synthe("gi-kuraboni youkoso.");
    }
  }

  // debug
//  Serial.println("************");
  Serial.println(passflg);

  delay(150);
}

// 測距センサから取得したvoltsから距離を測定
float getDistance(float v){
  float    ret_dis;

  ret_dis = (65 * pow(v, -1.10));
  // 2.5v以上は20cmとする
  if(v > 2.5){
    ret_dis = 20; 
  }

  return ret_dis;
}

// 測距センサの距離から遠たか判定
//  戻り値:
//  0:通過していない
//  1:通過
int getPass(float d){
  int    ret_pass;
  
  ret_pass = 0;
  // 50cm未満になったら遠たとする
  if(d < 50){
    ret_pass = 1;
  }
  
  return ret_pass;
}

/*----------------------------------------------------
	音声合成用の関数
-----------------------------------------------------*/
#define I2C_ADDR_AQUESTALK 0x2E // AquesTalk pico LSIのデフォルトのI2Cアドレス

// LSIがコマンドを受信可能かチェック
// 戻り値　0:Ready 1:Busy 2:Error
int AquesTalk_IsBusy()
{
	delay(10); // Busy応答は10msec以上待つ必要がある 連続して呼ばれた場合のため
	Wire.requestFrom(I2C_ADDR_AQUESTALK, 1);
	if(Wire.available()>0){
		byte c = Wire.read();
		if(c=='>')	return 0;	// Ready応答
		else		return 1;	// busy応答
	}
	else {
		return 2; //ERR: NOACK または応答が無い。I2Cの配線をチェックすべし
	}
}


// 音声合成開始	引数に音声記号列を指定
void AquesTalk_Synthe(String &strMsg)
{
    char msg[256];
    strMsg.toCharArray(msg, 256);
	AquesTalk_Synthe(msg);
}

// 音声合成開始	引数に音声記号列を指定
// 最後に"\r"を送信
void AquesTalk_Synthe(const char *msg)
{
	AquesTalk_Cmd(msg);
	AquesTalk_Cmd("\r");
}

// LSI にコマンド送信
void AquesTalk_Cmd(const char *msg)
{
	// Wireの制約で、一度に送れるのは32byteまで
	// AquesTalk picoへは一度に128byteまで送れるので、
	// Wire.beginTransmission()～Wire.endTransmission()を複数回に分けて呼び出す
	const char *p = msg;
	for(;*p!=0;){
		Wire.beginTransmission(I2C_ADDR_AQUESTALK);
		// Wireの制約で、一度に送れるのは32byteまで
		for(int i=0;i<32;i++){
			Wire.write(*p++);
			if(*p==0) break;
		}
		Wire.endTransmission(); // 実際はこのタイミングで送信される
	}
}

