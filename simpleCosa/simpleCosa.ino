const int humTierra = A1;
const int humAire = A2;

const int led1 = 2;
const int led2 = 3;
const int motor = 4;

int stateLed1 = 0;
int stateLed2 = 0;
int stateMotor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motor, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  delay (200);

  if(analogRead(humTierra) <= 600){
    stateLed1 = 1;
  }else{
    stateLed1 = 0;
  }

  if(analogRead(humAire) <= 200){
    stateLed2 = 1;
  }else{
    stateLed2 = 0;
  }

  if((stateLed1 == 1) && (stateLed2 == 1)){
    stateMotor = 1;
  }else{
    stateMotor = 0;
  }

  digitalWrite(led1, stateLed1);
  digitalWrite(led2, stateLed2);
  digitalWrite(motor, stateMotor);
}
