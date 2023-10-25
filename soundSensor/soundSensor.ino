const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

const int bot = 12;

const int trigger = 9;
const int echo = 8;

const int potent = A1;

int pot = 0;

int triggDistance = 0;

int isOpen = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (trigger, OUTPUT);
  pinMode (echo, INPUT);
  pinMode (bot, INPUT);
  
  digitalWrite (trigger, 0);

  

  Serial.begin(9600);

}

void loop() {
  long t;
  long d;

  int botState = digitalRead (bot);


  if (isOpen == 0){
    if (botState == 1){
      isOpen = 1;
    }
  }else{
    if (botState == 1){
      isOpen = 0;
    }
  }

  delay(100);

  if (isOpen == 1){
    digitalWrite (led2, 1);
  }else{
    digitalWrite (led2, 0);
  }

  pot = analogRead (potent);
  triggDistance = pot/100;

  digitalWrite (trigger, 1);
  delay(1);
  digitalWrite (trigger, 0);

  t = pulseIn (echo,1);
  d = t/60;

  if (d < triggDistance){
    digitalWrite(led1,1);
  }else{
    digitalWrite(led1,0);
  }

  delay (10);
}
