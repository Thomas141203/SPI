int pedestrians_button = 2;
int pedestrians_green = 9;
int pedestrians_red = 8;

int car_green = 10;
int car_orange = 11;
int car_red = 12;

bool is_pedestrians_button_press = false;

void setup(){
  Serial.begin(9600);
  pinMode(pedestrians_button,INPUT);
  pinMode(pedestrians_green,OUTPUT);
  pinMode(pedestrians_red,OUTPUT);
  pinMode(car_green,OUTPUT);
  pinMode(car_orange,OUTPUT);
  pinMode(car_red,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pedestrians_button), pedestrians_button_on_press, CHANGE);
}

void loop(){
  digitalWrite(pedestrians_green,LOW);
  digitalWrite(pedestrians_red,HIGH);
 
  digitalWrite(car_orange,LOW);
  digitalWrite(car_red,LOW);
  digitalWrite(car_green,HIGH);

  delay(3000);

  int delay_time_needed=0;
  if(is_pedestrians_button_press){
    delay_time_needed=5000;
  }else{
    delay_time_needed=3000;
  }
  car_goes_red(delay_time_needed);
}

void pedestrians_button_on_press(){
    is_pedestrians_button_press=digitalRead(pedestrians_button);
}



void car_goes_red(int delay_time_needed){
    digitalWrite(car_green,LOW);
    digitalWrite(car_orange,HIGH);
    delay(1000);
    digitalWrite(car_orange,LOW);
    digitalWrite(car_red,HIGH);
    // à partir du temps de delay on détecte si on a besoin d'activer le feu piéton ou non
    if(delay_time_needed==5000){
      pedestrians_goes_green();
    }
    delay(delay_time_needed);
}

void pedestrians_goes_green(){
  digitalWrite(pedestrians_red,LOW);
  digitalWrite(pedestrians_green,HIGH);
}
