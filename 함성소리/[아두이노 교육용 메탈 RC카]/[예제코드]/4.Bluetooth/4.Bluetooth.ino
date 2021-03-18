/* 이 소스는 에듀이노(Eduino)에 의해서 번역, 수정, 작성되었고 소유권 또한 에듀이노의 것입니다. 
  소유권자의 허락을 받지 않고 무단으로 수정, 삭제하여 배포할 시 법적인 처벌을 받을 수도 있습니다. 
*/
#include <SoftwareSerial.h> // 시리얼 통신을 위한 라이브러리 선언
 
#define BT_RXD A4  // 아두이노의 A4번핀을 RX(받는 핀)로 설정
#define BT_TXD A5  // 아두이노 A5번핀을 TX(보내는 핀)로 설정 
SoftwareSerial bluetooth(BT_RXD, BT_TXD); // 블루투스 통신을 위한 설정
 
void setup() 
{
  Serial.begin(9600); // PC와 아두이노간 시리얼 통신속도를 9600bps로 설정
  bluetooth.begin(9600); // 블루투스와 아두이노간 시리얼 통신속도를 9600bps로 설정
}
 
void loop()
{
  if (bluetooth.available()) {        // 블루투스로부터 받은 데이터가 있으면
    Serial.write(bluetooth.read());  // 시리얼 모니터(PC)로 전송
  }
  if (Serial.available()) {          // 시리얼 모니터로부터 받은 데이터가 있으면
    bluetooth.write(Serial.read());  // 블루투스로 전송
  }
}
