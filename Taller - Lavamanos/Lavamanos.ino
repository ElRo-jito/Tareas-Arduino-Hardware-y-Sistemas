#define echoPin 2 
#define trigPin 3 
byte ledVerde = 7;
byte ledRojo = 8;

int contador = 0;
int reset = 0;
long duration; 
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance <= 50 && contador < 10){
    digitalWrite(ledRojo, 1);
    digitalWrite(ledVerde, 0);
    contador += 1;
    delay(1000);
  }else if(distance <= 50 && contador >= 10){
    digitalWrite(ledVerde, 1);
    digitalWrite(ledRojo, 0);
    delay(1000);
    contador = 0;
  }else{
    digitalWrite(ledVerde, 0);
    digitalWrite(ledRojo, 0);
    delay(1000);
  }

  if(distance >= 51 && contador < 10){
    contador = 0;
    digitalWrite(ledRojo, 1);
    digitalWrite(ledVerde, 0);
    delay(1000);
    digitalWrite(ledRojo, 0);
    digitalWrite(ledVerde, 0);
    delay(1000);
  }
}
  
}