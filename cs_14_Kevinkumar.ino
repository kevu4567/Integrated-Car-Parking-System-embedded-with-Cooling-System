#include <LiquidCrystal.h> // includes the LiquidCrystal Library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 7;
const int echoPin = 8;
long duration;
int distanceCm, distanceInch;
#define CONTRAST_PIN 6

void setup() {
  Serial.begin(9600);
  pinMode(CONTRAST_PIN, OUTPUT);
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  analogWrite(CONTRAST_PIN,68);
}

void loop() {
  digitalWrite(trigPin, LOW); 
  delay(250);
  
  digitalWrite(trigPin, HIGH);
  delay(250);
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  
  //String send = String();
  Serial.write(distanceCm);
  
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(250);
  
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(250);
}