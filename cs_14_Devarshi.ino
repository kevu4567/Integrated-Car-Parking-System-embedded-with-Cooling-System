// C++ code
//

#include <SoftwareSerial.h>

SoftwareSerial mySerial(13, 10);

const int potentiometer_Pin = A0; // Arduino pin connected to Potentiometer pin
const int buzzer_Pin        = 3; // Arduino pin connected to Buzzer's pin
const int analog_Threshold  = 50;
int serial_distance;
const int motorPin = 9;
int fanSpeed = 0;
float value; //Create a float variable to store the received value
const int LEDPIN = 12;

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(buzzer_Pin, OUTPUT); // set arduino pin to output mode
}

void loop()
{
   // A1 Module
  int analogValue = analogRead(potentiometer_Pin); // read the input on analog pin
  if(Serial.available() > 0){
    serial_distance = Serial.read();
    
   int delayDuration = serial_distance % 50; // Computes the delay interval for the buzzer and LED
    
    if(serial_distance < 50){  // if the distance is less than 50 cm, it will beep as well as emits the LED
        tone(buzzer_Pin, 1000, 200);    // turn on Piezo Buzzer
      	digitalWrite(LEDPIN, HIGH); 
      	delay(delayDuration * 10);
      	digitalWrite(LEDPIN, LOW);
        delay(delayDuration * 10);
    }else{
      digitalWrite(LEDPIN, LOW);
    } 
  }
    // A2 Module
   // Adjust the fan speed
    mySerial.readBytes((byte*)&value, sizeof(value)); //Read the float value from the SoftSerial port
    updateFan(value);
  
}

void updateFan(float temperatureC) {
  // Mapping the temperature to the fan's speed
  fanSpeed = map(temperatureC, 20, 40, 0, 255);
  
  // Controlling the speed of the DC motor through the transistor
  analogWrite(motorPin, fanSpeed);

   Print the fan speed to the serial monitor
   Serial.print("Fan speed: ");
   Serial.println(fanSpeed);
}