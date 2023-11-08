const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;

const int boton = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);

  pinMode(boton,INPUT);
}

void loop() {
  if (digitalRead(boton)==1){
    setAllLeds (1);
  }else{
    setAllLeds (0);
  }
}

void setAllLeds (int state){
  digitalWrite (led1,state);
  digitalWrite (led2,state);
  digitalWrite (led3,state);
  digitalWrite (led4,state);
  digitalWrite (led5,state);
  digitalWrite (led6,state);
}