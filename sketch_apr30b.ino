#define motorPin 4
#define motorAna 5
#define ultSence 9
#define CdS 3
#define Res 2
#define ultSence 4
#define reset 15
#define LED 2
int cou=0,lastSen=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin,HIGH);
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(reset, INPUT);
  lastSen=analogRead(ultSence);
}
int readSec=0;
int temp,multi;
bool isPerson=false;
void loop() {
  // put your main code here, to run repeatedly:
  temp=map(analogRead(CdS),0,1023,0,25);
  multi=map(analogRead(Res),0,1023,0,10);
  //Serial.print(multi);
  //Serial.println(temp);
  if(temp>18&&cou>0){
    analogWrite(motorAna,temp*multi/2);
  }else{
    analogWrite(motorAna,0);
  }
   if(readSec+1<millis()/100){
    Serial.println(cou);
    lastSen=analogRead(ultSence);
    if(lastSen<150){
      cou=1;
    }else{
      cou=0;
    }
    readSec=millis()/100;
    Serial.println(lastSen);
  }
  if(cou>0) digitalWrite(LED,HIGH);
  else digitalWrite(LED,LOW);
  if(digitalRead(reset)==LOW){
    cou=0;
  }
}
