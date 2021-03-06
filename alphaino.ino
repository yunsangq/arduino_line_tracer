
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

#define VALUE  400

void setup() { 
  //Serial.begin(9600);
  Robot.begin();   
  Robot.stop();    
}

/*
    왼쪽바퀴  오른쪽바퀴
       b       a
*/

// L,R 이 반대 motors(a, b)
// -가 커질수록 앞으로 가는 속도 증가
// +가 커질수록 뒤로 가는 속도 증가
// 왼쪽회전 -> R,L => a > b
// 오른쪽회전 -> R,L => a < b
long cnt=0;
int check =0;
void loop() {
  cnt++;

  /*
  if((Robot.Front_IRread(0) < VALUE) && (Robot.Front_IRread(1) < VALUE) && (Robot.Front_IRread(2) < VALUE) && (Robot.Front_IRread(3) < VALUE) && (Robot.Front_IRread(4) < VALUE) && (Robot.Front_IRread(5) < VALUE)){
    Robot.motors(-230, -230);
    delay(500);
  }
  *//*
  //코스에 따라 수정
  if(cnt<20000){
    if((Robot.Front_IRread(0) < VALUE) && (Robot.Front_IRread(1) < VALUE) && (Robot.Front_IRread(2) < VALUE) && (Robot.Front_IRread(3) < VALUE) && (Robot.Front_IRread(4) < VALUE) && (Robot.Front_IRread(5) < VALUE)){
      Robot.motors(-230, -230);
      //delay(500);
    }
  }*/

  //정지
  if( cnt>370000 )
  {
    
     if((Robot.Front_IRread(0) > VALUE) && (Robot.Front_IRread(1) > VALUE) && (Robot.Front_IRread(2) > VALUE) && (Robot.Front_IRread(3) > VALUE) && (Robot.Front_IRread(4) > VALUE) && (Robot.Front_IRread(5) > VALUE) && (Robot.Rear_IRread(0) > VALUE) && (Robot.Rear_IRread(1) > VALUE) && (Robot.Rear_IRread(2) > VALUE) && (Robot.Rear_IRread(3) > VALUE) && (Robot.Rear_IRread(4) > VALUE) && (Robot.Rear_IRread(5) > VALUE)){
        Robot.motors(0,0);
        delay(10000);
      }
      
   }

  else if(check == 1){
    //우회전 방향전환 => |a| > |b| (a>0, b<0)
    if((Robot.Front_IRread(4) < VALUE) && (Robot.Front_IRread(5) < VALUE) && (Robot.Front_IRread(3) < VALUE)){
      Robot.motors(80, -150);
      delay(200);
    }
    
    //좌회전 방향전환 => |a| < |b| (a<0, b>0) 
    else if((Robot.Front_IRread(0) < VALUE) && (Robot.Front_IRread(1) < VALUE) && (Robot.Front_IRread(2) < VALUE)){ 
      Robot.motors(-150, 80);
      delay(200);
    }
    else if( (Robot.Front_IRread(2) < VALUE) || (Robot.Front_IRread(3) < VALUE))
    {
        Robot.motors(-230, -230);
    }
    else if( (Robot.Front_IRread(0) < VALUE) || (Robot.Front_IRread(1) < VALUE))
    {
        Robot.motors(-150, 80);
    }
    else if( (Robot.Front_IRread(4) < VALUE) || (Robot.Front_IRread(5) < VALUE))
    {
        Robot.motors(80, -150);
    }
  
    
  }
    else if(cnt < 90000){
    
    if( (Robot.Front_IRread(2) < VALUE) || (Robot.Front_IRread(3) < VALUE))
    {
        Robot.motors(-230, -230);
    }
    else if( (Robot.Front_IRread(0) < VALUE) || (Robot.Front_IRread(1) < VALUE))
    {
        Robot.motors(-150, 80);
    }
    else if( (Robot.Front_IRread(4) < VALUE) || (Robot.Front_IRread(5) < VALUE))
    {
        Robot.motors(80, -150);
    }
    //우회전 방향전환 => |a| > |b| (a>0, b<0)
    else if((Robot.Front_IRread(4) < VALUE) && (Robot.Front_IRread(5) < VALUE) && (Robot.Front_IRread(3) < VALUE)){
      Robot.motors(80, -150);
      delay(200);
    }
    
    //좌회전 방향전환 => |a| < |b| (a<0, b>0) 
    else if((Robot.Front_IRread(0) < VALUE) && (Robot.Front_IRread(1) < VALUE) && (Robot.Front_IRread(2) < VALUE)){ 
      Robot.motors(-150, 80);
      delay(200);
    }
    
  }

  //코스에 따라 수정
  else if( cnt>=90000 && cnt<170000)
  {
    //직진
    // 0 0 1 1 0 0
    /*
    if((Robot.Front_IRread(0) > VALUE) && (Robot.Front_IRread(1) > VALUE) && (Robot.Front_IRread(2) > VALUE) && (Robot.Front_IRread(3) > VALUE) && (Robot.Front_IRread(4) > VALUE) && (Robot.Front_IRread(5) > VALUE)){
      Robot.motors(-160,-100);
      check=1;
    }
    else if((Robot.Front_IRread(2) < VALUE) || (Robot.Front_IRread(3) < VALUE)){
      Robot.motors(-160, -180);
    }

    //우회전 직진 보정 => |a| < |b| (a<0, b<0)
    // 0 0 0 0 1 1 OR
    else if((Robot.Front_IRread(4) < VALUE) || (Robot.Front_IRread(5) < VALUE)){
      Robot.motors(-30, -100);
    }

    //좌회전 직진 보정 => |a| > |b| (a<0, b<0)
    // 1 1 0 0 0 0 OR
    else if((Robot.Front_IRread(0) < VALUE) || (Robot.Front_IRread(1) < VALUE)){
      Robot.motors(-100, -30);
    }
    */
    if((Robot.Front_IRread(0) > VALUE) && (Robot.Front_IRread(1) > VALUE) && (Robot.Front_IRread(2) > VALUE) && (Robot.Front_IRread(3) > VALUE) && (Robot.Front_IRread(4) > VALUE) && (Robot.Front_IRread(5) > VALUE)){
      Robot.motors(-170,-100);
      check=1;
    }
    else if((Robot.Front_IRread(2) < VALUE) || (Robot.Front_IRread(3) < VALUE)){
      Robot.motors(-230, -230);
    }

    //우회전 직진 보정 => |a| < |b| (a<0, b<0)
    // 0 0 0 0 1 1 OR
    else if((Robot.Front_IRread(4) < VALUE) || (Robot.Front_IRread(5) < VALUE)){
      Robot.motors(80, -150);
    }

    //좌회전 직진 보정 => |a| > |b| (a<0, b<0)
    // 1 1 0 0 0 0 OR
    else if((Robot.Front_IRread(0) < VALUE) || (Robot.Front_IRread(1) < VALUE)){
      Robot.motors(-150, 80);
    }
    
}

  


  
}
