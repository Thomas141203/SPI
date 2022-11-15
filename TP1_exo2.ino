void setup(){
  pinMode(13,OUTPUT);
}

void loop(){
  power_on_led();
  delay(4000);
  power_off_led();
  delay(2000);
  power_on_led();
  delay(8000);
}

void power_on_led(){
  digitalWrite(13,HIGH);
}

void power_off_led(){
  digitalWrite(13,LOW);
}
