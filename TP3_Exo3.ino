#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5,4);
int temperaturePin = 0;
int temperature = 0;
int humiditePin = 1;
int humidite = 0;

void setup() {
  
  lcd.begin(16,2);
  
  Serial.begin(9600);
}

void loop() {
  
  // le capteur de température envoit des données de façon linéaire
  // on utilise donc une fonction de transfert
  temperature = analogRead(temperaturePin)*23/47-2346/47;
  humidite = analogRead(humiditePin)*23/47-2346/47;
  
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print(temperature);
  lcd.print('c');
  lcd.setCursor(0,1);
  lcd.print(humidite);
  Serial.println(analogRead(temperaturePin));
  lcd.print('%');
  delay(500);
}
