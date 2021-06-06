char dato;
void setup()
{
  Serial.begin(9600);
}

void loop()
{ if(Serial.available()){
  dato = Serial.read();
Serial.println("Como andai?");}
 delay(1000);
}