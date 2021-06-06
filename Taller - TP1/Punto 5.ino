const int boton1 = 2;
const int boton2 = 3;

int stop;

int ver1 = 4, ama1 = 5, roj1 = 6;
int ver2 = 7, ama2 = 8, roj2 = 9;
int tiempo1 = 5000, tiempo2 = 2000, tiempo3 = 5000, tiempo4 = 2000;
unsigned long ta = 0, tb = 0, tc = 0, td = 0;
bool estado = true, estado1 = true;
void setup(){
  Serial.begin(9600);
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(boton1),codboton1,RISING);
  attachInterrupt(digitalPinToInterrupt(boton2),codboton2,RISING);
  
  pinMode(ver1, OUTPUT);
  pinMode(ama1, OUTPUT);
  pinMode(roj1, OUTPUT);
  pinMode(ver2, OUTPUT);
  pinMode(ama2, OUTPUT);
  pinMode(roj2, OUTPUT);
  digitalWrite(ver1,1);
  digitalWrite(roj2,1);
}

void codboton1(){
  stop = 1;
  digitalWrite(ver1, 1);
  digitalWrite(ama1, 1);
  digitalWrite(roj1, 1);
  digitalWrite(ver2, 1);
  digitalWrite(ama2, 1);
  digitalWrite(roj2, 1);
}
void codboton2(){
  stop = 0;
  digitalWrite(ver1, 0);
  digitalWrite(ama1, 0);
  digitalWrite(roj1, 0);
  digitalWrite(ver2, 0);
  digitalWrite(ama2, 0);
  digitalWrite(roj2, 0);
}
void loop(){
  
  if(stop == 0){
    
  if(millis() >= tiempo1 + td && estado==true){
    if(estado1 == true){
      estado=false;
      digitalWrite(ver1,0);
      digitalWrite(ama1,1);
      
      ta=millis();
    }
  }
  if(millis() >= tiempo2 + ta && estado == false){
    if(estado1 == true){
      estado1 = false;
      digitalWrite(ama1,0);
      digitalWrite(roj1,1);
      digitalWrite(ver2,1);
      digitalWrite(roj2,0);
      tb=millis();
    }
  }
  if(millis() >= tiempo3 + tb && estado1 == false){
    if(estado == false){
      estado = true;
      estado1 = false;
      digitalWrite(ver2,0);
      digitalWrite(ama2,1);
      tc=millis();
    }
  }
    if(millis() >= tiempo4 + tc && estado == true){
    if(estado1 == false){
      estado = true;
      estado1 = true;
      digitalWrite(ama2,0);
      digitalWrite(roj2,1);
      digitalWrite(ver1,1);
      digitalWrite(roj1,0);
      td=millis();
    }
  }
  delay(1);
  }
}
