const int led0 = 2;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;
const int led5 = 7;

const int echo = 10;
const int trigger = 11;



void setup() {
  // put your setup code here, to run once:
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);

  pinMode(echo,INPUT);
  pinMode(trigger,OUTPUT);

  digitalWrite(trigger,0);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long t;
  long d;

  digitalWrite(trigger,1);
  delay(1);
  digitalWrite(trigger,0);

  t = pulseIn(echo,1);
  d = t/10;

  Serial.println(d);

  if (d < 90){
    digitalWrite(led0,1);
  }else{
    digitalWrite(led0,0);
  }

  if (d < 70){
    digitalWrite(led1,1);
  }else{
    digitalWrite(led1,0);
  }

  if (d < 50){
    digitalWrite(led3,1);
  }else{
    digitalWrite(led3,0);
  }
  
  if (d < 30){
    digitalWrite(led4,1);
  }else{
    digitalWrite(led4,0);
  }

  if (d < 10){
    digitalWrite(led5,1);
  }else{
    digitalWrite(led5,0);
  }

  delay(100);
}

