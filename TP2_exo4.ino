#include <LiquidCrystal.h>

int LED2 = 8;
int LED1 = 9;
int LED0 = 10;

int button0 = 13;
int button1 = 3;
int button2 = 2;

int rand0 = 0;
int rand1 = 0;
int rand2 = 0;

int cmptTry = 0;
bool canPlay = true;
bool alreadyRand0 = false;
bool alreadyRand1 = false;
bool alreadyRand2 = false;

// initialisation, on définit les ports pour RS, E et D4 à D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd_print_rands();
  pinMode(button2, INPUT);
  pinMode(button1, INPUT);
  pinMode(button0, INPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED0, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button0), onPressButton0, RISING);
  attachInterrupt(digitalPinToInterrupt(button1), onPressButton1, RISING);
  attachInterrupt(digitalPinToInterrupt(button2), onPressButton2, RISING);
}

void loop() {
}

void onPressButton0() {
  Serial.print('yes');
  if (canPlay && !alreadyRand0) {
    rand0 = random(1, 10);
    onPressButton();
  }
}

void onPressButton1() {
  if (canPlay && !alreadyRand1) {
    rand1 = random(1, 10);
    alreadyRand1 = true;
    onPressButton();
  }
}

void onPressButton2() {
  Serial.print('yes');
  if (canPlay && !alreadyRand2) {
    rand2 = random(1, 10);
    alreadyRand2 = true;
    onPressButton();
  }
}

void onPressButton() {
  lcd_print_rands();
  check3TimesPress();
}

void clignote_LED() {
  for (int x = 0; x < 10; x++) {
    power_on_LED();
    delay(1000);
    power_off_LED();
    delay(1000);
  }
}

void power_on_LED() {
  digitalWrite(LED0, HIGH);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
}

void power_off_LED() {
  digitalWrite(LED0, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void lcd_game_over() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print('GAME OVER');
}

void lcd_print_rands() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd_print_rand(0, rand0);
  lcd.setCursor(5, 0);
  lcd_print_rand(1, rand1);
  lcd.setCursor(0, 1);
  lcd_print_rand(2, rand2);
}

void lcd_print_rand(int index, int value) {
  lcd.print('T');
  lcd.print(index);
  lcd.print(':');
  lcd.print(value);
}

void reset_rand() {
  rand0 = 0;
  rand1 = 0;
  rand2 = 0;
  alreadyRand0 = false;
  alreadyRand1 = false;
  alreadyRand2 = false;
}

void reset() {
  reset_rand();
  cmptTry = 0;
  lcd.clear();
  canPlay = true;
  lcd_print_rands();
}

void check3TimesPress() {
  if (rand0 != 0 && rand1 != 0 && rand2 != 0) {
    if (rand0 == rand1 && rand1 == rand2) {
      canPlay = false;
      clignote_LED();
      canPlay = true;
    } else {
      canPlay = false;
      lcd_print_rands();
      delay(1000);
      cmptTry += 1;
      reset_rand();
      canPlay = true;
      if (cmptTry == 3) {
        canPlay = false;
        lcd_game_over();
        power_on_LED();
        delay(10000);
        reset();
      }
    }
  }
}
