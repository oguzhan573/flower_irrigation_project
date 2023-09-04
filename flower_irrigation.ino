#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


int sensor = A0;
int role = 2;

int deger;


void setup() {
  lcd.init();

  lcd.setCursor(3, 0);
  pinMode(role, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {

  deger = analogRead(sensor);
  deger = map(deger, 0, 1023, 100, 0);

  if (deger < 25) {
    Serial.print(deger);
      lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("nem orani yuzde ");
    lcd.setCursor(1, 1);
    lcd.print("25in altinda");
  
    
    digitalWrite(role, LOW);


  } else 
  {
     lcd.clear();
    Serial.print(deger);
    digitalWrite(role, HIGH);
  }
}
