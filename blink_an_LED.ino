int ledPin = 6;
int delayTime = 1000;

void setup(){
  pinMode (ledPin,OUTPUT);
}
void loop(){
  digitalWrite(ledPin,HIGH);
  delay(delayTime);
  digitalWrite(ledPin,LOW);
  delay(delayTime);
}