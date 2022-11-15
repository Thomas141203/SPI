#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 4, 5, 6 ,7);

void setup(){
  // indique le nombre de caractères et de lignes
  lcd.begin(16,2); 
}

void loop(){
  // parcourt verticalement le lcd
  for(int y=0;y<2;y++){
    // parcourt horizontalement le lcd
    for(int x=0;x<16;x++){
      // nettoie le lcd des caractères précédent
      lcd.clear()
      // place le curseur en x,y
      lcd.sertCursor(x,y);
      // affiche le smiley
      lcd.print(":)");
      // attend 1 secondes pour changer la position du smiley
      delay(1000);
    }
  }
}
