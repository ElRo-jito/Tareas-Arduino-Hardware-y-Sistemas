int distancia = 0;
int Led1 = 8;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void setup()
{
    pinMode(8, OUTPUT);
 attachInterrupt(digitalPinToInterrupt(2), medir,RISING);
 Serial.begin(9600);
}
void loop()
{
    distancia = 0.01723 * readUltrasonicDistance(7, 6); //guarda en "distancia" la distancia en cm
    Serial.print("La distancia medida es de ");
    Serial.print(distancia);
    Serial.println(" cm.");
}
void medir(){
   //se detecta movimiento
    Serial.println("SENSOR ACTIVADO");
    
    digitalWrite(Led1, HIGH);
    delay(500);
    digitalWrite(Led1, LOW);
    delay(500);     
}