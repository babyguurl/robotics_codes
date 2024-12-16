#define RelayPin 7
#define IR_SENSORPIN 10
void setup(){
  pinMode(RelayPin,OUTPUT);
  pinMode(IR_SENSORPIN,INPUT);
  digitalWrite(RelayPin,HIGH);
}
void loop(){
  int irstate = digitalRead(IR_SENSORPIN);
  if(irstate==HIGH){
    digitalWrite(RelayPin,HIGH);
  }else
   digitalWrite(RelayPin,LOW);
}
