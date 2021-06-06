int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
pinMode(triggerPin, OUTPUT); // Clear the trigger
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);
// Sets the trigger pin to HIGH state for 10 microseconds
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT);
// Reads the echo pin, and returns the sound wave travel time in microseconds
return pulseIn(echoPin, HIGH);
}

void setup()
{
Serial.begin(9600);

}

void loop()
{
distancia = 0.01723 * readUltrasonicDistance(4, 5);
Serial.println(distancia);
delay(1000); // Delay a little bit to improve simulation performance
}