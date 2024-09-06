#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
byte i,j,k;
byte buka[8] = {
  0b01111,
  0b11110,
  0b11100,
  0b11000,
  0b11100,
  0b11110,
  0b01111,
  0b00000
};

byte tutup[8] = {
  0b00000,
  0b01100,
  0b11110,
  0b11110,
  0b11110,
  0b01100,
  0b00000,
  0b00000
};

void setup() {  
  lcd.createChar(1, buka);
  lcd.createChar(2, tutup); 
  lcd.begin(16, 2); 
}

void loop() {
  lcd.clear(); 
  lcd.print(" Inkubatek Jogja");
 //lcd.setCursor(0,15);
  for(i=0;i<16;i++){
    lcd.setCursor(i,0);
    lcd.write(1);
    j=i-1;
    lcd.setCursor(j,0);
    lcd.print(" ");
    delay(300);
    k=i+1;
    lcd.setCursor(k,0);
    lcd.write(2);
    lcd.setCursor(i,0);
    lcd.print(" ");
    delay(300);
  }
}

