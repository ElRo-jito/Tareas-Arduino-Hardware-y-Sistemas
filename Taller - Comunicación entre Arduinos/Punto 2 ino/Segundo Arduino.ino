String distancia;
char c;

void setup()
{
Serial.begin(9600);
pinMode(7, OUTPUT);
}

void loop(){
  while(Serial.available()>0){
    //avisa cuando haya info. disponible en el puerto serial
    c=Serial.read();
    distancia+=c;
  }
  //convertir distancia a int
  Serial.println(distancia.toInt());
  if(distancia.toInt() < 150){
    digitalWrite(7, LOW);
  }
  else{
    digitalWrite(7, HIGH);
  }
  delay(1000);
  distancia = "";
}