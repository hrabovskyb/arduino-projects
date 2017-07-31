#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x3F

#define BACKLIGHT_PIN  7
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
#define B1_pin  3
#define BLPOL   POSITIVE

#define  LED_OFF  0
#define  LED_ON  1
LiquidCrystal_I2C lcd(LCD_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin,B1_pin,BLPOL);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);
  lcd.clear();
  delay(1000);

//  lcd.setBacklightPin(BACKLIGHT_PIN,NEGATIVE);
//  lcd.setBacklight(LED_ON);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //lcd.home();

  
  lcd.setCursor(0,0);
  lcd.print("LINE 1");
  lcd.setCursor(0,1);
  lcd.print("LINE 2");
  lcd.setCursor(0,2);
  lcd.print("LINE 3");
  lcd.setCursor(0,3);
  lcd.print("LINE 4");
  
}
