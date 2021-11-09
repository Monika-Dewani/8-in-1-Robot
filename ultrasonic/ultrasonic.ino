#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 1);
#define trigPin 7
#define echoPin 6
int ir1=A5;
int ir2=A4;
int M11=2;
int M12=3;
int M21=4;
int M22=5;
int buz=13;
int but1=8;
int but2=9;
int but3=10;

long Duration,Distance;

void setup() {
 Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  pinMode(buz,OUTPUT);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(13,OUTPUT);
 pinMode(but1,INPUT);
 pinMode(but2,INPUT);
 pinMode(but3,INPUT);
   
  // put your setup code here, to run once:

}

void loop() {
//if (digitalRead(but1)==1&&digitalRead(but2)==1&&digitalRead(but3)==1)
  ///////wall follower//////
  
  {
    digitalWrite(trigPin,0);
  delayMicroseconds(2);
   digitalWrite(trigPin,1);
  delayMicroseconds(10);
   digitalWrite(trigPin,0);
   Duration=pulseIn(echoPin,HIGH);
   Distance=(Duration/2)/29.1;
   
   Serial.print("Distance=");
   Serial.println(Distance);
   delay(50);
    digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
   if(Distance<30)
   {
    digitalWrite(M11,0);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    delay(1000);
    digitalWrite(M11,1);
    digitalWrite(M12,0);
    
   }
}


  

     
///////bluetooth///
//else if (digitalRead(but1)==0&&digitalRead(but2)==1&&digitalRead(but3)==1)
//{
//if (mySerial.available())
//  {int code =mySerial.read();
//  if (code=='r')
//  {
//    digitalWrite(M11,0);
//    digitalWrite(M12,0);
//    digitalWrite(M21,1);
//    digitalWrite(M22,0);
//    delay(100);
//    code='s';
//    
//    }
//    else if(code=='l')
//    {
//      digitalWrite(M11,1);
//    digitalWrite(M12,0);
//    digitalWrite(M21,1);
//    digitalWrite(M22,1);
//    delay(100);
//    code='s';
//    }
//    
//    else if(code=='f')
//    {
//       digitalWrite(M11,1);
//    digitalWrite(M12,0);
//    
//    
//    digitalWrite(M21,1);
//    digitalWrite(M22,0);
//    }
//    else if(code=='b')
//    {
//       digitalWrite(M11,0);
//    digitalWrite(M12,1);
//    
//     digitalWrite(M21,0);
//    digitalWrite(M22,1);
//    }
//    else if(code=='s')
//    {
//    digitalWrite(M11,0);
//    digitalWrite(M12,0);
//    
//     digitalWrite(M21,0);
//    digitalWrite(M22,0);   
//  
//    }
//    else if(code=='o')
//    {digitalWrite(M11,1);
//    digitalWrite(M12,0);
//    
//     digitalWrite(M21,0);
//    digitalWrite(M22,1);   
//       
//    }
//    else if(code=='p')
//    {digitalWrite(M11,0);
//    digitalWrite(M12,1);
//    
//     digitalWrite(M21,1);
//    digitalWrite(M22,0);   
//       
//    }
// 
//    }
//}
//else if(digitalRead(but1)==0&&digitalRead(but2)==0&&digitalRead(but3)==0)
//{
//  if(analogRead(ir1)>700)
//  {
//    digitalWrite(M21,1);
//    digitalWrite(M22,0);
//    }
//    else 
//    {
//    digitalWrite(M21,0);
//    digitalWrite(M22,0);
//    }
//
//    if(analogRead(ir2)>700)
//  {
//    digitalWrite(M11,1);
//    digitalWrite(M12,0);
//    }
//    else 
//    {
//    digitalWrite(M11,0);
//    digitalWrite(M12,0);
//    }
//  }
}

