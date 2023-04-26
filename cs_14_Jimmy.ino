#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 10);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorPin = A0;

void setup() {
  mySerial.begin(9600);
  lcd.begin(16, 2);

  lcd.print("Temperature:");

}

void loop() {
  int sensorValue = analogRead(sensorPin);
  
  // Convert the analog reading to Celsius temperature
  float temperatureC = (sensorValue * 0.0048828125 - 0.5) * 100;
  
  lcd.setCursor(0, 1);
  lcd.print(temperatureC);
  lcd.print("C");
  
  // sending bytes to the other arduino
  mySerial.write((byte*)&temperatureC, sizeof(temperatureC));


  // Delay for 1 second before reading the temperature again
  delay(1000);
}

