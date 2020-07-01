/* I2C LCD with Arduino example code. More info: https://www.makerguides.com */
// Include the libraries:
// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C 
#include <LiquidCrystal_I2C.h> // Library for LCD
// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
const int thermisistorPin = A0; // thermisistorPin
const int redLED = 11; // red LED
const int greenLED = 12; // green LED
const int yellowLED = 13; // yellow LED
int count = 0;

void setup() {
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print("Hello World!"); // Print the string "Hello World!"
}
void loop() {
  // Print 'Hello World!' on the first line of the LCD:
  lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  count ++;
  lcd.print("Temp: " + String(count) + char(223) + "C" );
  delay(500);
}
