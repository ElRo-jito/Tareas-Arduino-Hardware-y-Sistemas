int activarIzq = 5;
int motorIzq1 = 6;
int motorIzq2 = 7;
int activarDer = 8;
int motorDer1 = 9;
int motorDer2 = 10;
String lectura;
char c;
int Estado = 0;
void setup() {
  
  
  Serial.begin (9600);
  pinMode (activarIzq, OUTPUT);
  pinMode (motorIzq1, OUTPUT);
  pinMode (motorIzq2, OUTPUT);  
  
  pinMode (activarDer, OUTPUT);
  pinMode (motorDer1, OUTPUT);
  pinMode (motorDer2, OUTPUT);  
  
  digitalWrite (activarIzq, HIGH);
  digitalWrite (activarDer, HIGH);
  
}
void loop() {
  while(Serial.available()>0)
  {
  c=Serial.read();
  lectura+=c;
  }
 
  if(lectura.equals("W"))
  {
   Estado = 1; 
  }
  if(lectura.equals("S"))
  {
   Estado = 2; 
  }
  if(lectura.equals("A"))
  {
   Estado = 3; 
  }
  if(lectura.equals("D"))
  {
   Estado = 4; 
  }
  switch(Estado){
  case 1:
  digitalWrite (motorIzq1, LOW);
  digitalWrite (motorIzq2, HIGH);
  digitalWrite (motorDer1, LOW);
  digitalWrite (motorDer2, HIGH);
  break;
   
  case 2:
  digitalWrite (motorIzq1,HIGH);
  digitalWrite (motorIzq2,LOW);  
  digitalWrite (motorDer1,HIGH);
  digitalWrite (motorDer2,LOW);  
  break;
  
  case 3:
  digitalWrite (motorIzq1, HIGH);
  digitalWrite (motorIzq2, LOW);
  digitalWrite (motorDer1, LOW);
  digitalWrite (motorDer2, HIGH);
  break;  
  
  case 4:
  digitalWrite (motorIzq1, LOW);
  digitalWrite (motorIzq2, HIGH);
  digitalWrite (motorDer1, HIGH);
  digitalWrite (motorDer2, LOW);
  break;
  }
  lectura="";
  delay(200);
}