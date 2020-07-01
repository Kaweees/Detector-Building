#include <LiquidCrystal_I2C.h> // Library for LCD

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
const int ThermistorPin = A0; // thermisistor model: TMP36

float Vout = 0; // Volyage between thermisistor and resistor of known resistance (in milliVolts)
int Vin = 5; // the original voltage in Volts
float temp = 0; // in degrees Celsius
const int greenLED = 11; // green LED
const int redLED = 12; // red LED
const int blueLED = 13; // blue LED

const int greenMin = 15;
const int greenMax = 25;
const int redMin = 25;
const int redMax = 35;
const int blueMin = 35;
const int blueMax =  45;

int count = 0;
void setup() {
  lcd.init(); // Initiate the LCD
  lcd.backlight();
  pinMode(greenLED, OUTPUT); // Declare the green LED as an output
  pinMode(redLED, OUTPUT); // Declare the red LED as an output
  pinMode(blueLED, OUTPUT); // Declare the yellow LED as an output
}

void loop() {
  // put your main code here, to run repeatedly:
  Vout = (analogRead(ThermistorPin) * ((Vin)/1024.0)); // the voltage at the thermistor Pin
  temp = (((Vout) - 0.5) * 100.0);
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row
  lcd.print("Temp: " + String(temp) + char(223) + "C" );
  lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("Voltage: " + String(Vout) + " V" );

  //temp = int(temp);
  if (greenMin <= temp and temp < greenMax){
    digitalWrite(greenLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    }
  else if ((redMin <= temp) and (temp < redMax)){
    digitalWrite(redLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    }
  else if ((blueMin <= temp) and (temp < blueMax)){
    digitalWrite(blueLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    }
  else{
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    }
  delay(1000);
}
