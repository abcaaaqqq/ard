#include <Servo.h>


unsigned long startMillis;
unsigned long endMillis;
unsigned long executionTime;

Servo gws_micro_2bbmg[6];
float servoHornAngle[2],angleCommand[2],A,B;  

void setup() {
  Serial.begin(115200);  // シリアル通信の設定
  Serial.flush();

  gws_micro_2bbmg[0].attach(3); //digital_pin 3をPWM出力に指定(VC用)
  gws_micro_2bbmg[1].attach(5); //digital_pin 5をPWM出力に指定(指モータ用)
  gws_micro_2bbmg[2].attach(6); //digital pin 6をPWM出力に指定
  gws_micro_2bbmg[3].attach(9); //digital pin 9をPWM出力に指定
  gws_micro_2bbmg[4].attach(10); //digital pin 10をPWM出力に指定
  gws_micro_2bbmg[5].attach(11); //digital pin 11をPWM出力に指定

 
}

void loop() {
  startMillis = millis();
  if (Serial.available()) {
    String receivedData = Serial.readString();  // データの受信

    // カンマで受信データを分割
    String values[9];
    int currentIndex = 0;
    int previousCommaIndex = -1;
    for (int i = 0; i < receivedData.length(); i++) {
      if (receivedData.charAt(i) == ',') {
        values[currentIndex] = receivedData.substring(previousCommaIndex + 1, i);
        currentIndex++;
        previousCommaIndex = i;
      }
    }
    // 最後のデータを取得
    values[currentIndex] = receivedData.substring(previousCommaIndex + 1);

    // データを変換して表示
    String cmd_header = values[0];
    int angle1 = values[1].toInt();
    int angle2 = values[2].toInt();
    int angle3 = values[3].toInt();
    int angle4 = values[4].toInt();
    int speed1 = values[5].toInt();
    int speed2 = values[6].toInt();
    int speed3 = values[7].toInt();
    int speed4 = values[8].toInt();
    
    if (cmd_header[0] == 'M' && cmd_header[1] == 'P') {
      // モータに角度指令を設定

      if (angle2 != 500) {
        // angle2 の指令が '500' でない場合、モータ2を angle2 度に回転させる
        // ここにモータ2の制御コードを追加
        survoMotorControl2(angle2);//５番ピン
//        Serial.println("Motor 2: Move to " + String(angle2) + " degrees");
      } else {
        // angle2 の指令が '500' の場合、モータ2は動かさない
//        Serial.println("Motor 2: Do not move");
        }{
        delay(500);
      }
      
      if (angle3 != 500) {
        // angle3 の指令が '500' でない場合、モータ3を angle3 度に回転させる
        // ここにモータ3の制御コードを追加
        survoMotorControl3(angle3); //6番ピン
//        Serial.println("Motor 3: Move to " + String(angle3) + " degrees");
      } else {
        // angle3 の指令が '500' の場合、モータ3は動かさない
//        Serial.println("Motor 3: Do not move");
      }
      
      if (angle1 != 500) {
        // angle1 の指令が '500' でない場合、モータ1を angle1 度に回転させる
        // ここにモータ1の制御コードを追加
        survoMotorControl(angle1);//3番ピン
//        Serial.println("Motor 1: Move to " + String(angle1) + " degrees");
      } else {
        // angle1 の指令が '500' の場合、モータ1は動かさない
//        Serial.println("Motor 1: Do not move");
      }
      
      if (angle4 != 500) {
        // angle4 の指令が '500' でない場合、モータ4を angle4 度に回転させる
        // ここにモータ4の制御コードを追加
        survoMotorControl4(angle4);//11番ピン
//        Serial.println("Motor 4: Move to " + String(angle4) + " degrees");
      } else {
        // angle4 の指令が '500' の場合、モータ4は動かさない
//        Serial.println("Motor 4: Do not move");
      }
    } else if (cmd_header[0] == 'R' && cmd_header[1] == 'P') {
      // モータに角度指令を設定

      if (angle3 != 500) {
        // angle3 の指令が '500' でない場合、モータ3を angle3 度に回転させる
        // ここにモータ3の制御コードを追加
        survoMotorControl3(angle3);//6番ピン
//        Serial.println("Motor 3: Move to " + String(angle3) + " degrees");
      } else {
        // angle3 の指令が '500' の場合、モータ3は動かさない
//        Serial.println("Motor 3: Do not move");
      }
      
      if (angle1 != 500) {
        // angle1 の指令が '500' でない場合、モータ1を angle1 度に回転させる
        // ここにモータ1の制御コードを追加
        survoMotorControl(angle1); //3番ピン
//        Serial.println("Motor 1: Move to " + String(angle1) + " degrees");
      } else {
        // angle1 の指令が '500' の場合、モータ1は動かさない
//        Serial.println("Motor 1: Do not move");
        }{
        delay(500);
      }
      
      if (angle2 != 500) {
        // angle2 の指令が '500' でない場合、モータ2を angle2 度に回転させる
        // ここにモータ2の制御コードを追加
        survoMotorControl2(angle2);//5番ピン
//        Serial.println("Motor 2: Move to " + String(angle2) + " degrees");
      } else {
        // angle2 の指令が '500' の場合、モータ2は動かさない
//        Serial.println("Motor 2: Do not move");
      }
      
      if (angle4 != 500) {
        // angle4 の指令が '500' でない場合、モータ4を angle4 度に回転させる
        // ここにモータ4の制御コードを追加
        survoMotorControl4(angle4);//11番ピン
//        Serial.println("Motor 4: Move to " + String(angle4) + " degrees");
      } else {
        // angle4 の指令が '500' の場合、モータ4は動かさない
//        Serial.println("Motor 4: Do not move");
      }
    } else {
//      Serial.println("Invalid command header");
    }endMillis = millis();
    executionTime = endMillis - startMillis;
    Serial.print("Execution time: ");
    Serial.print(executionTime);
    Serial.println(" ms");
  }
}

void survoMotorControl(float val)//親指
{
  survoMotorControlForHand(3,val);
}

void survoMotorControl2(float val)//4指
{
  survoMotorControlForHand(5,val);
}

void survoMotorControl3(float val)//4指
{
  survoMotorControlForHand(6,val);
}

void survoMotorControl4(float val)//手首
{     
  survoMotorControlForHand(11,val);
}

void survoMotorControlForHand(int pinNo,float val)
{   
  switch(pinNo){
      case 3: gws_micro_2bbmg[0].write( (int)(val) ); break;
      case 5: gws_micro_2bbmg[1].write( (int)(val) ); break;
      case 6: gws_micro_2bbmg[2].write( (int)(val) ); break;
      case 9: gws_micro_2bbmg[3].write( (int)(val) ); break;
      case 10: gws_micro_2bbmg[4].write( (int)(val) ); break;
      case 11: gws_micro_2bbmg[5].write( (int)(val) ); break;
  }
}

void zeroAdjustment()
{
  survoMotorControlForHand(11,0.0);// Zero point
}
