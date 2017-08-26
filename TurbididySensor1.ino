// This example uses the analog output mode of the sensor

// Turbididy sensor leads:
// Blue lead analog signal
// Red wire 5VDC
// Black wire Ground

int sensor_in = A0;        // Connect turbidity sensor to Analog Pin 0

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object, the other pin is pin 10 on the Uno
  pinMode(13, OUTPUT);  // initialize digital pin 13 as an output.
  Serial.begin(9600); //Baud rate: 9600
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(sensor_in);// read the input on sensor_in:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//  Serial.println(voltage); // print out the value you read:
  Serial.print("The turbidy sensor reads: "); // print out the text to explain what data you will read:
  Serial.println(sensorValue); // print out the scaled value:
  Serial.print(" The actual voltage read is : "); // print out the text to explain what data you will read:
  Serial.println(voltage); // print out the voltage read:
  Serial.println(); // print a blank line

  myservo.write(180);              // tell servo to go to position 180
  delay(1000);                       // waits 1 second for the servo to reach the position
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}