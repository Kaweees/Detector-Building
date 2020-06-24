const int redLED = 3;
const int greenLED = 4;
const int yellowLED = 5;
void setup() {
  // put your setup code here, to run once:
  // initialize the digital pin as an output.
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

}

void loop() {
  int temp = Serial.read();
  Serial.print("Number received: ");
  Serial.println(temp);
  // put your main code here, to run repeatedly:
  if ((20 >= temp) && (temp >= 10)){
    digitalWrite(greenLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    delay(1000); // basically time.sleep(miliseconds)
    digitalWrite(greenLED, LOW);      // turn the LED off by making the voltage LOW
    }
  else if ((40 >= temp) && (temp > 20)){
    digitalWrite(yellowLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    delay(1000); // basically time.sleep(miliseconds)
    digitalWrite(yellowLED, LOW);      // turn the LED off by making the voltage LOW
    }
  else if ((60 >= temp) && (temp > 40)){
    digitalWrite(redLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    delay(1000); // basically time.sleep(miliseconds)
    digitalWrite(redLED, LOW);      // turn the LED off by making the voltage LOW
    }
  else{
    digitalWrite(greenLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    digitalWrite(yellowLED, HIGH);     // turn the LED on (HIGH is the voltage level)
    digitalWrite(redLED, HIGH);     // turn the LED on (HIGH is the voltage level)
  }

}
