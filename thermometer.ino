// imports
#include <LiquidCrystal_I2C.h> // Library for LCD
// setup devices
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
const int ThermistorPin = A0; // thermisistor model: TMP36
const int greenLED = 11; // green LED
const int redLED = 12; // red LED
const int blueLED = 13; // blue LED
// change these in accordance with proctor decision
// the LEDs will light up if the temperature is within a certain range 

const int greenMin = 0; // green LED range Min 
const int greenMax = 25; // green LED range Max
const int redMin = 25; // green LED range Min
const int redMax = 50; // green LED range Max
const int blueMin = 50; // green LED range Min
const int blueMax =  75; // green LED range Max

float Vout = 0; // Volyage between thermisistor and resistor of known resistance (in milliVolts)
int Vin = 5; // the original voltage in Volts
float temp = 0; // in degrees Celsius
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
  // get the the temperature based off of the thermisitor's voltage
  Vout = (analogRead(ThermistorPin) * ((Vin)/1024.0)); // the voltage at the thermistor Pin
  temp = (((Vout) - 0.5) * 100.0);
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row
  lcd.print("Temp: " + String(temp) + char(223) + "C" );
  lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("Voltage: " + String(Vout) + " V" );
  // lighting up the LEDs based on the temperature:
  if (greenMin <= temp and temp < greenMax){ 
    digitalWrite(greenLED, HIGH);     // turn the green LED on (HIGH is the voltage level) if the temperature is within a certain range 
    }
  else if ((redMin <= temp) and (temp < redMax)){
    digitalWrite(redLED, HIGH);     // turn the red LED on (HIGH is the voltage level) if the temperature is within a certain range 
  }
  else if ((blueMin <= temp) and (temp < blueMax)){
    digitalWrite(blueLED, HIGH);     // turn the blue LED on (HIGH is the voltage level) if the temperature is within a certain range 
  }
  else{
    digitalWrite(greenLED, LOW); // all the LEDs off (LOW is the voltage level) if the temperature is out of all of the LEDs' ranges 
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
  }
  delay(1000);
}
