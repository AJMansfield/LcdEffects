/*
  Custom Characters and Effects

  This sketch demonstrates how you can create your own custom character effects.

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

// This effect puts a diaresis (the two-dots thing, e.g. ä) on the character.
// (doesn't work on every letter, just lowercase letters that are small enough)
void diaeresis(uint8_t* glyph){ //this is the signature for a character effect
  glyph[0] |= B01010;
}

uint8_t cat [] = { // defines a custom "cat face" character
  0b10001,
  0b11111,
  0b10001,
  0b11011,
  0b10101,
  0b10001,
  0b01110,
};

void setup() {
  lcd.begin(16, 2); //change to match the size of your LCD
  lcd.setBacklight(255);

  fx.setSlotRange(0,7); // prevent fx from using slot 0
  lcd.createChar(7, cat);

  lcd.setCursor(0,0);
  lcd.write(byte(7)); // write the custom cat character.


   char text[] = "Schrodinger "; // puts the text in an array so we can work with it
  // note that the 'o' is the 5th character, so it will be at index 4.
  
  fx.applyEffect(text[4], diaeresis); // put the dots over the 'o'

  lcd.setCursor(2,0); // print out the text with effects
  lcd.print(text);


}
void loop() {

}
