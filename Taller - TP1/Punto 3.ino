const int boton = 5;
int counter;
long tiempo = 5000;

void setup(){
  Serial.begin(9600);
  pinMode(boton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(boton),fcontador,RISING);
}

void loop(){
  millis();
  if((millis() - tiempo) > 5000){
    tiempo = millis();
    counter = counter/ 5;
    Serial.print("Se presiono el boton ");
    Serial.print(counter);
    Serial.println(" por segundo");
    counter = 0;
  }
  delay(1);
}

void fcontador(){
  
  counter += 1;
}
// No anda