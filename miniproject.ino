int trig = 3;   
int echo = 2;    

int revleft7 = 7;       
int fwdleft8 = 8; 
int revright9 = 9;  
int fwdright10 = 10;  

long duration, distance;

void setup() {
  
  delay(random(500,2000)); 
  Serial.begin(9600);
  pinMode(revleft7, OUTPUT);    
  pinMode(fwdleft8, OUTPUT);
  pinMode(revright9, OUTPUT);
  pinMode(fwdright10, OUTPUT);
  
  pinMode(trig, OUTPUT);       
  pinMode(echo, INPUT);        
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);   
  digitalWrite(trig, HIGH);    
  delayMicroseconds(10);
  duration = pulseIn(echo, HIGH); 
  distance = duration / 58.2;  
  delay(10);
 
  if (distance > 19)            
  {
    digitalWrite(fwdright10, HIGH);               
    digitalWrite(revright9, LOW);
    digitalWrite(fwdleft8, HIGH);                                
    digitalWrite(revleft7, LOW);                                                       
  }

  if (distance < 18)
  {
    digitalWrite(fwdright10, LOW);               
    digitalWrite(revright9, LOW);
    digitalWrite(fwdleft8, LOW);                                
    digitalWrite(revleft7, LOW);
    delay(500);
    digitalWrite(fwdright10, LOW);             
    digitalWrite(revright9, HIGH);
    digitalWrite(fwdleft8, LOW);                                
    digitalWrite(revleft7, HIGH);
    delay(500);
    digitalWrite(fwdright10, LOW);                  
    digitalWrite(revright9, LOW);
    digitalWrite(fwdleft8, LOW);                                
    digitalWrite(revleft7, LOW);  
    delay(100);  
    digitalWrite(fwdright10, HIGH);       
    digitalWrite(revright9, LOW);   
    digitalWrite(revleft7, LOW);                                 
    digitalWrite(fwdleft8, LOW);  
    delay(500);
  }
}