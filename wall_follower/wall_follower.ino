#define trigPin 7
#define echoPin 6
int M11=2;
int M12=3;
int M21=4;
int M22=5;
int buz=13;


long Duration,Distance;

void setup() {
 Serial.begin(9600);
  
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  pinMode(buz,OUTPUT);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(13,OUTPUT);

  // put your setup code here, to run once:

}

void loop() {

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



