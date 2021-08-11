//ASYONI ELEKTRONIK

#include "DHT.h"
#include "LCD.h" 
#include "LiquidCrystal_I2C.h" 
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); 
#define DHTPIN 3 // Pin Arduino yang digunakan D3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
   lcd.setBacklightPin(3,POSITIVE); 
   lcd.setBacklight(HIGH);
 
  lcd.setCursor(0,0);
  lcd.print("Sensor DHT11");
  dht.begin();
}

void loop() {
  lcd.clear();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
           
  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.print(t);
  lcd.print(" 'C");

  lcd.setCursor(0,1);
  lcd.print("Hum : ");
  lcd.print(h);
  lcd.print(" %");
  delay(1000);
}
