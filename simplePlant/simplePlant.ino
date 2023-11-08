const int potent1 = A1;
const int potent2 = A2;

const int hum = A4;

const int led1 = 6; //status 1
const int led2 = 7; //status 2

const int ledMotor = 8; //"motor"

const int ledBoton = 9; //debug

const int boton = 2;

const int limit = 800;

int state1;
int state2;
int stateMotor;
int stateBoton;

void setup() {
  // put your setup code here, to run once:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (ledMotor, OUTPUT);
  pinMode (ledBoton, OUTPUT);

  pinMode (boton, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);

  Serial.println(analogRead(hum));

  if (digitalRead(boton)==1){
    if(stateBoton == 1){
      stateBoton = 0;
    }else{
      stateBoton = 1;
    }
  }


  if (analogRead(potent1) >= 600){
    state1 = 1;
  }else{
    state1 = 0;
  }

  if (analogRead(potent2) >= 600){
    state2 = 1;
  }else{
    state2 = 0;
  }

  if ((state1==1) && (state2==1) && (stateBoton==1)){
    stateMotor = 1;
  }else{
    stateMotor = 0;
  }

  digitalWrite(led1,state1);
  digitalWrite(led2,state2);
  digitalWrite(ledMotor, stateMotor);
  digitalWrite(ledBoton, stateBoton);

}

