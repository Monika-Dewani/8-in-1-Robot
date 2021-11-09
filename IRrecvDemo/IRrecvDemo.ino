/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 12;
int M11=2;
int M12=3;
int M21=4;
int M22=5;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()

{
  Serial.begin(9600);
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
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
      digitalWrite(M11,1);
    digitalWrite(M12,0);
    digitalWrite(M21,0);
    digitalWrite(M22,0);
    delay(500);
    digitalWrite(M11,0);
      }
      else if(results.value==6 || results.value==2054 )
    {
      digitalWrite(M11,0);
    digitalWrite(M12,0);
    digitalWrite(M21,1);
    digitalWrite(M22,0);
    delay(500);
    digitalWrite(M21,0);
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
