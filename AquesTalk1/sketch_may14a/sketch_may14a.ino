/*
 Hello Talk
 http://blog-yama.a-quest.com/?eid=970150
*/

#include <Wire.h>

void setup(){
  Wire.begin();
}

void loop(){
  while(AquesTalk_IsBusy());
  AquesTalk_Synthe("bukkorosu.");
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

