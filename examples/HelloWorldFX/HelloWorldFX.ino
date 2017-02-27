/*
  Hello World FX

  This circut demonstrates basic use of the LcdEffects library by displaying
  some static text.

  The arduino is connected to the LCD in this example over I2C, but this should work just
  fine with other types of LCDs, just swap out the library headers and declaration to
  the ones for what you have.

  Created 2017-02-23
  By Anson Mansfield

*/
#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h> // should work with any LCD library
LiquidCrystal_PCF8574 lcd(0x3f);

void make_char(char c, uint8_t* image){ //need this function to pass to LcdEffects
  lcd.createChar(c, image); // so it knows how to make custom characters
}

#include <LcdEffects.h> // the core library
#include <Effects.h> // a collection of common effects
LcdEffects<> fx(make_char); // initialize the LcdEffects library

void setup() {
  lcd.begin(16, 2); //change to match the size of your LCD
  lcd.setBacklight(255);
}
void loop() {
  char text[] = "Hello, FX!"; // puts the text in an array so we can work with it
  lcd.setCursor(0,0);
  lcd.print(text); //print the text to the first line without any effects (for comparison)
  
  fx.applyEffect(text, 0, 5, effect::italic); // bold "Hello"
  fx.applyEffect(text, 7, 10, effect::bold); // italicize "LCD!"

  lcd.setCursor(0,1); //now print the text to the second line
  lcd.print(text);

  delay(1000);
}
