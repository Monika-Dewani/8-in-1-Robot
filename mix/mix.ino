int A0=a;
int A1=b;
int A2=c;
int A3=d;
int A4=e;
int A5=f;
void setup() {
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
 
  digitalWrite(a, HIGH);  
  delay(500);                       
  digitalWrite(a, LOW);   
  delay(500);
  digitalWrite(b, HIGH);  
  delay(500);                       
  digitalWrite(b, LOW);   
  delay(500);
  digitalWrite(c, HIGH);  
  delay(500);                       
  digitalWrite(c, LOW);   
  delay(500);
  digitalWrite(d, HIGH);  
  delay(500);                       
  digitalWrite(d, LOW);   
  delay(500);
  digitalWrite(e, HIGH);  
  delay(500);                       
  digitalWrite(e, LOW);   
  delay(500);
  digitalWrite(f, HIGH);  
  delay(500);                       
  digitalWrite(f, LOW);   
  delay(500);
  
                         
}
