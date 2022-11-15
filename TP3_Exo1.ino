#include <LiquidCrystal.h>
#include <Servo.h>

const int buzzerPin = 2;
const int trigPin = 10;
const int echoPin = 9;
int distance_max=320;
long distance=0;
long temps=0;

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  
  lcd.begin(16,2);
  
  pinMode(buzzerPin,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Le trigger reçoit un courant 5V pendant 10 microsecondes
  // ce qui génère une onde ultrason.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Grâce à echoPin et la fonction pulseIn, 
  // on lit la valeur du temps nécessaire à l'onde sonore pour réaliser un aller-retour
  temps = pulseIn(echoPin, HIGH);
  // On calcul la distance sachant la vitesse du son est d'environ 340 m/s dans l'air
  distance = temps/29/2;
  digitalWrite(buzzerPin,HIGH);
  
  // On affiche la distance sur le lcd
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(distance);
  lcd.print(" cm");
  delay(500);
}
  
