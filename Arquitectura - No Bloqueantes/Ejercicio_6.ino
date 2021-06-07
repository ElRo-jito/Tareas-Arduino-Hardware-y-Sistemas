unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
int tiempodeespera = 5000;

const int boton = 2;
int led = 1;

void setup(){
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  pinMode(boton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(boton),fcontador,RISING);
}
void loop(){
  tiempo1 = millis();
  if((tiempo1 - tiempo2) > tiempodeespera){
    tiempo2 = tiempo1;
    led=led/-1;
  }
  if(led == 1){
    digitalWrite(6, HIGH);
  }else{
    digitalWrite(6, LOW);
  }
  delay(1);
}

void fcontador(){
  tiempodeespera -= 500;
  if(tiempodeespera <= 0){
    tiempodeespera = 5000;
  }
}
