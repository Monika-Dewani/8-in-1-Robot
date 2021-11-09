#include <SoftwareSerial.h>
//SoftwareSerial mySerial(11, 1);


void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  //mySerial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  if (Serial.available())
  {int code =Serial.read();
  if (code=='r')
  {
    Serial.print("right");
    //digitalWrite(13,1);
    }
    else if(code=='l')
    {
        Serial.print("left");
    }
    
    else if(code=='u')
    {
         Serial.print("up");
    
    
    }
    else if(code=='d')
    {
        Serial.print("down");
    }
    
 
    }
}
    
  // put your main code here, to run repeatedly:
