const int ledPower = 8;
const int motor = 7;
const int ledSensor = 6;

const int boton = 2;

const int pot = A1;
const int hum = A2;

int powerState = 0;
int motorState = 0;
int sensorState = 0;

int humedad = 0;
int limite = 0;

void setup() {
  pinMode(ledPower, OUTPUT);
  pinMode(ledSensor, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(boton, INPUT);

  Serial.begin(9600);

}

void loop() {
  delay(200);

  limite = analogRead(pot);
  humedad = analogRead(hum);

  Serial.print("humedad: "); Serial.print(humedad);Serial.println();

  if (humedad <= limite){
    sensorState = 1;
  }else{
    sensorState = 0;
  }

  if (digitalRead(boton)==1){
    changePowerState();
  }

  digitalWrite(ledPower, powerState);
  digitalWrite(ledSensor, sensorState);

  if ((sensorState == 1) && (powerState==1)){
    regar(2);
    powerState = 0;
  }
}

void regar (int time) {
  time *= 4;
  for (int i = 0; i < time ; i++){
    digitalWrite(motor, 1);
    delay(250);
    digitalWrite(motor, 0);
    delay(250);
  }
}

void changePowerState () {
  if (powerState == 0){
      powerState = 1;
  }else{
    powerState = 0;
  }
}

