String Hola;
void setup() {
    Serial.begin(9600);
     }

void loop() {

        while (Serial.available()) {
        delay(1); 
        char c = Serial.read();
        Hola += c;
        }

      if (Hola.length() >0) {
        
      Serial.println(Hola);

    if (Hola == "Hola") {
    Serial.println("Como estas");
          
        }
        else; {    
      	}
        
        
        Hola="";
   }
}