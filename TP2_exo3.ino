int analogOutput = A0;

void setup() {
  Serial.begin(9600);
  pinMode(analogOutput,OUTPUT);
}

void loop() {
  // incrémente le voltage d'environ 0.05V toutes les 20 ms en partant de 0
  for(int x=0;x<1024;x+=10){ 
    analogWrite(analogOutput,x);
    Serial.println(x);
    delay(20);
  }
  
  // décrémente le voltage d'environ 0.05V toutes les 20 ms en partant de 5V
  for(int x=1023;x>=0;x-=10){
    analogWrite(analogOutput,x);
    Serial.println(x);
    delay(20);
  }
}
