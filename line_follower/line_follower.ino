
int ir1=A5;
int ir2=A4;
int M11=2;
int M12=3;
int M21=4;
int M22=5;

void setup() {
 Serial.begin(9600);

  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  
   
  // put your setup code here, to run once:

}

void loop() {

 Serial.println( analogRead(ir1));
 Serial.println( analogRead(ir1));
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

