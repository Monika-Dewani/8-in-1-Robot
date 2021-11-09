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
 //pinMode(but1,INPUT);
 //pinMode(but2,INPUT);
 //pinMode(but3,INPUT);
}

void loop()
{
 if (mySerial.available())
  {int code =mySerial.read();
  if (code=='r')
  {
    digitalWrite(M11,0);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    delay(100);
    code='s';
    
    }
    else if(code=='l')
    {
      digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,1);
    delay(100);
    code='s';
    }
    
    else if(code=='f')
    {
       digitalWrite(M11,1);
    digitalWrite(M12,0);
    
    
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    }
    else if(code=='b')
    {
       digitalWrite(M11,0);
    digitalWrite(M12,1);
    
     digitalWrite(M21,0);
    digitalWrite(M22,1);
    }
    else if(code=='s')
    {
    digitalWrite(M11,0);
    digitalWrite(M12,0);
    
     digitalWrite(M21,0);
    digitalWrite(M22,0);   
  
    }
    else if(code=='o')
    {digitalWrite(M11,1);
    digitalWrite(M12,0);
    
     digitalWrite(M21,0);
    digitalWrite(M22,1);   
       
    }
    else if(code=='p')
    {digitalWrite(M11,0);
    digitalWrite(M12,1);
    
     digitalWrite(M21,1);
    digitalWrite(M22,0);   
       
    }
 
    }
}
