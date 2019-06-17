// PhotoResistor (LDR) on pin A0
// Servo on pin 9
 
#include <Servo.h>
 
Servo servo1;

const int lightPin = A0;     // LDR Pin
const int servoPin = 9;      // Servo Pin 
int angle = 0;               // Servo Angle
int servoMove = 70;          // The amount the servo moves in degrees
int count = 0;               // Counts number of dodges

// Begin serial communication with a computer if one is plugged in via USB
// Then links Servo Pin to Servo Object
void setup() {
Serial.begin(9600);
    servo1.attach(servoPin);
}

// Main program loop
void loop() {
 //This line is used for calibrating the arduino to your tv
 //It will print to your computer the current light level reading off of the LDR sensor
 //You can delete this line once you calibrate your code so you can see the dodge counter more easily
Serial.println(analogRead(lightPin));
 
 //Slight delay prevents the servo from trying to dodge the same lightning strike twice
delay(200);

// Checks to see if lightning has flashed 
// The "400" is the number you will need to change that will trigger the servo to dodge in the game
if(analogRead(lightPin) >= 400){
  // The next two lines provide a counter of the number of lightning bolts currently dodged if you have the Arduino plugged into a PC
  count++;
  Serial.println(count);

  // Moves servo 70 degrees to press x button
  for (angle = 0; angle <= servoMove; angle += 10) {
    servo1.write(angle);
    delay(30);  
  }

  // Moves servo 70 degrees back to its original position
  for (angle = servoMove; angle <= 0; angle -= 10) {
    servo1.write(angle);
    delay(30);  
  }
  }

}
