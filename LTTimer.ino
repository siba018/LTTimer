unsigned long startTime;
const char ledPin = 13;
const char btnPin = 2;
const char bellPin = 3;
char endFlg=0;
void setup(){
  pinMode(btnPin,INPUT);
  pinMode(bellPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
}

void loop(){
  digitalWrite(ledPin,LOW);
  while(LOW == digitalRead(btnPin));
  while(HIGH == digitalRead(btnPin));
  digitalWrite(bellPin,HIGH);
  delay(50);
  digitalWrite(bellPin,LOW);
  startTime = millis();
  while(((millis()-startTime)<=300000) && (LOW == digitalRead(btnPin))){
    digitalWrite(ledPin,HIGH);
    if(endFlg==0 && ((millis()-startTime)>=240000)){
      digitalWrite(bellPin,HIGH);
      delay(50);
      digitalWrite(bellPin,LOW);
      endFlg=1;
    }
  }
  digitalWrite(ledPin,LOW);
  if(endFlg==1){
    for(int i=0;i<3;i++){
      digitalWrite(bellPin,HIGH);
      delay(50);
      digitalWrite(bellPin,LOW);
      delay(200);
    }
    endFlg=0;
  }
  else{
    while(HIGH == digitalRead(btnPin));
  }
}





