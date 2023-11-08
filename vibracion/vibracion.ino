const int vib = 8;
const int led = 2;

void setup() {
  pinMode(vib, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  digitalWrite(led,1);
  delay(200);
  digitalWrite(led,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  

 if(digitalRead(vib)==1){
  digitalWrite(led,1);
 }else{
  digitalWrite(led,0);
 }
}
