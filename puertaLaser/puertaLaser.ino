const int laser = 4;
const int led = 7;
const int buzz = 9;

const int photo = A1;


void setup() {
  // put your setup code here, to run once:
  pinMode(laser, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);

  digitalWrite(laser,1);

  Serial.begin(9600);
}

void loop() {
  delay(200);
  
  if (analogRead(photo) < 300){
    digitalWrite(led,1);
    hacerRuido();
  }else{
    digitalWrite(led,0);
  }

}

void hacerRuido () {
  tone(buzz,600,500);
  delay(500);
}
