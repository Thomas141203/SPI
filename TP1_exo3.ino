/*
  Reminder : 
  the goal of this exercice is to simulate an intersection light
  loop :
    3s green
    1s orange
    3s red
*/

int green = 10;
int orange = 11;
int red = 12;

void setup(){
  pinMode(green,OUTPUT);
  pinMode(orange,OUTPUT);
  pinMode(red,OUTPUT);
}

void loop(){
  //green start
  
  digitalWrite(orange,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);

  delay(3000);
  
  //green end
  //orange start
  
  digitalWrite(green,LOW);
  digitalWrite(orange,HIGH);
  
  delay(1000);
  
  //orange end
  //red start
  
  digitalWrite(orange,LOW);
  digitalWrite(red,HIGH);
  
  delay(3000);
  
  //red end
}
