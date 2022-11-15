#include <LiquidCrystal.h>
#include <Servo.h>

Servo servo_temperature;
Servo servo_humidite;
Servo servo_vent;
int ventPin = 2;
int temperaturePin = 1;
int humiditePin = 0;
int vent = 0;
int temperature = 0;
int humidite = 0;

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
 
  lcd.begin(16,2);
 
  servo_vent.attach(1);
  servo_temperature.attach(3);
  servo_humidite.attach(2);
}

void loop() {
 
  vent = getRealValue(analogRead(ventPin));
  temperature = getRealValue(analogRead(temperaturePin));
 // vu que les valeurs sont linéaires je peux donc faire une fonction de transfert
 // j’ai donc f(valeur analogique) = a(valeur analogique)+b = température
  humidite = getRealValue(analogRead(humiditePin));
 
  int vent_angle = vent*180/125;
  int humidite_angle = humidite*180/100;
  int temperature_angle = (temperature+40)*180/165;
  // le capteur de température va de -40 à 125
  // il a donc une plage de 165°C
  // je considère que le degrée 0 est -40 ( -40+40 = 0 )
  // je considère que le degrée 180 est 125 ( 125+40 = 165 )
  // pour calculer l'angle j'effectue un bête produit en croix
 
  servo_vent.write(vent_angle);
  servo_temperature.write(temperature_angle);
  servo_humidite.write(humidite_angle);
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(temperature);
  lcd.print('C');
  lcd.setCursor(0,1);
  lcd.print(humidite);
  lcd.print('%');
  for(int x=0;x<3;x++){ // on affiche 3 espaces
    lcd.print(' ');
  }

  lcd.print(vent);
  lcd.print('k');lcd.print('m');lcd.print('/');lcd.print('h');
 
  delay(500);
}

int getRealValue(int value){
    return value*23/47-2346/47;
}
