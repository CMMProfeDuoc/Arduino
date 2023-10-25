const int micIn = A0;

const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;

int micVolume = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);

  setLeds (1);
  delay (300);
  setLeds (0);
  delay(300);
  setLeds (1);
  delay (300);
  setLeds (0);


  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  micVolume = analogRead (micIn);
  Serial.println(micVolume);

  if (micVolume > 600){
    digitalWrite (led1,1);
  }else{
    digitalWrite (led1,0);
  }

  if (micVolume > 650){
    digitalWrite (led2,1);
  }else{
    digitalWrite (led2,0);
  }

  delay(100);
}

void setLeds (int state) {
  digitalWrite (led1, state);
  digitalWrite (led2, state);
  digitalWrite (led3, state);
  digitalWrite (led4, state);
}
