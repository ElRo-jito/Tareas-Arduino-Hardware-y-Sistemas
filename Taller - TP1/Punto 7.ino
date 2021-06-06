const int Echo = 8;
const int Trigger = 9; 
float Distancia;
long Tiempo;
const int boton = 2;

void setup(){
  pinMode(boton, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT); 
  attachInterrupt(digitalPinToInterrupt(boton),pulsador,RISING);
}

void loop(){
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  
  Tiempo = (pulseIn(Echo, HIGH)/2);
  
  Distancia = float(Tiempo * 0.0343);
  delay(1);
}

void pulsador(){
  Serial.print("Distancia del objeto: ");
  Serial.println(Distancia);
}