

#include <SoftwareSerial.h>   // library for extra rx & tx
SoftwareSerial mySerial(11, 1);  //11-rx & 1 is already tx
#include <IRremote.h>     // library for ir remote
int RECV_PIN = 12;         // pin to which output oin of tsop is connected

#define trigPin 7           // trigger pin of ultrasonic is connected to 7th pin of arduino
#define echoPin 6          // echo pin is connected to 6th pin
int ir1=A5;                // pins initialization
int ir2=A4;
int M11=2;
int M12=3;
int M21=4;
int M22=5;
int buz=13;
int but2=8;
int but3=9;
int but4=10;
int ldr1=A3;
int ldr2=A2;

IRrecv irrecv(RECV_PIN);   // taken fron ir remote program
decode_results results;

long Duration,Distance;    // variables

void setup() {
 Serial.begin(9600);
  mySerial.begin(9600);   //baudrate
  pinMode(M11,OUTPUT);     // this will work as an output pin
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  pinMode(buz,OUTPUT);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(buz,OUTPUT);
 pinMode(but2,INPUT);
 pinMode(but3,INPUT);
 pinMode(but4,INPUT);
 
 Serial.println("Enabling IRin");   // it will just print .......
 irrecv.enableIRIn(); // Start the receiver
 Serial.println("Enabled IRin");
 }

void loop() {

  ///////wall follower//////
if (digitalRead(but2)==0&&digitalRead(but3)==0&&digitalRead(but4)==0)  //switches position to ON position
{
  digitalWrite(trigPin,0);  //send logic 0 to pin trigpin
  delayMicroseconds(2);       //wait for 2usec
  digitalWrite(trigPin,1);   //send logic 1 to pin trigpin
  delayMicroseconds(10);     // wait for 10usec
  digitalWrite(trigPin,0);    // //send logic 0 to pin trigpin
  Duration=pulseIn(echoPin,HIGH);  //pulsein will calculate the time until it goes HIGH (when the sound sighnal is reflected back at echo pin)
  Distance=(Duration/2)/29.1;         // formula to calculate distance
   
  Serial.print("Distance=");     // will print distance as it is
  Serial.print(Distance);         // will printt value of distance
  Serial.println("cm")  ;          // will print cm as it is
   delay(500);                     // dealya of half sec(500 mili sec)
    digitalWrite(M11,1);            //will rotate the motors in forward direction
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    if(Distance<25 && Distance >10)         // robot will run in range 10cm to 25 cm
   {
    digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
   }
   else if(Distance>25)                    // robot will take turn to come under range 10cm to 25cm
   {
    digitalWrite(M11,0);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    }
    else if(Distance<10)
   {
    digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,0);
    digitalWrite(M22,0);
    }
   
}


  

     
///////bluetooth///
else if (digitalRead(but2)==0&&digitalRead(but3)==0&&digitalRead(but4)==1)  // but4 is at logic 1
{
if (mySerial.available())         //will check char data at receiver pin 11        
  {int code =mySerial.read();    // read the coming data and will save in variable code
  if (code=='r')                 // if my data is r
  {
    digitalWrite(M11,0);          // motor will rotate in right direction foe half sec and then will stop
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    delay(500);
    digitalWrite(M21,0);
    
    
    }
    else if(code=='l')
    {
      digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,1);
    delay(500);
    digitalWrite(M11,0);
    
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
    delay(1000); 
    digitalWrite(M11,0); 
    digitalWrite(M22,0);
       
    }
    else if(code=='p')
    {digitalWrite(M11,0);
    digitalWrite(M12,1);
    
     digitalWrite(M21,1);
    digitalWrite(M22,0);
    delay(1000);
    digitalWrite(M12,0);
    digitalWrite(M21,0);   
       
    }
 
    }
}
else if (digitalRead(but2)==0&&digitalRead(but3)==1&&digitalRead(but4)==0)
{
 if (irrecv.decode(&results)) 
 {
    Serial.println(results.value, DEC);
    if(results.value==2 || results.value==2050 )
    {
      digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
      }
      else if(results.value==4 || results.value==2052 )
    {
            digitalWrite(M11,0);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    delay(500);
    digitalWrite(M21,0);
      }
      else if(results.value==6 || results.value==2054 )
    {
      digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,0);
    digitalWrite(M22,0);
    delay(500);
    digitalWrite(M11,0);

      }
      else if(results.value==8 || results.value==2056)
    {
      digitalWrite(M11,0);
    digitalWrite(M12,1);
    digitalWrite(M21,0);
    digitalWrite(M22,1);
    delay(500);
    //digitalWrite(M21,0);
      }
       else if(results.value==5 || results.value==2055)
    {
      digitalWrite(M11,0);
    digitalWrite(M12,0);
    digitalWrite(M21,0);
    digitalWrite(M22,0);
    //delay(500);
    //digitalWrite(M21,0);
      }
      
    irrecv.resume(); // Receive the next value
  }
  delay(100); 
  }
else if (digitalRead(but2)==0&&digitalRead(but3)==1&&digitalRead(but4)==1)
  {
   if(analogRead(ir1)>700)
 {
  digitalWrite(M11,1);
  digitalWrite(M12,0);
  }
  else
  {
  digitalWrite(M11,0);
  digitalWrite(M12,0);
  }

  if(analogRead(ir2)>700)
 {
  digitalWrite(M21,1);
  digitalWrite(M22,0);
  }
  else
  {
  digitalWrite(M21,0);
  digitalWrite(M22,0);
  }
}
else if (digitalRead(but2)==1&&digitalRead(but3)==0&&digitalRead(but4)==0)
{
  if(analogRead(ldr1)<400)
 {
  digitalWrite(M11,1);
  digitalWrite(M12,0);
  }
  else
  {
  digitalWrite(M11,0);
  digitalWrite(M12,0);
  }

  if(analogRead(ldr2)<400)
 {
  digitalWrite(M21,1);
  digitalWrite(M22,0);
  }
  else
  {
  digitalWrite(M21,0);
  digitalWrite(M22,0);
  }
  }
 else if (digitalRead(but2)==1&&digitalRead(but3)==0&&digitalRead(but4)==1) 
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
  
    
   if(Distance<25 && Distance >10)
   {
    digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
   }
   else if(Distance>25)
   {
    digitalWrite(M11,0);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    }
    else if(Distance<10)
   {
    digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,0);
    digitalWrite(M22,0);
    }
  } 
else  
  {
    digitalWrite(M11,0);
    digitalWrite(M12,0);
    
     digitalWrite(M21,0);
    digitalWrite(M22,0);
    }
}

