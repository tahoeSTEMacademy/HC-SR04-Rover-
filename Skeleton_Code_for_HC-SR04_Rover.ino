// Include files tell the Arduino that you are using functions from a library. We are using the Adafruit Motor Shield V1 Library

#include <AFMotor.h>


// Creating "AF_DCMotor instances and letting the Arduino know where they are connected to on the motor shield

AF_DCMotor leftMotor(1);
AF_DCMotor rightMotor(2);

//create a global variable called "Distance". global means we can use it in any function
long distance;  

//defining what pins are going to be used for the HC-SR04 Sensor to make the code more readable
#define triggerPin A0
#define echoPin A1


void setup() {
    // set up Serial library at 9600 bps, so we can output messages to the computer for debugging
 Serial.begin(9600);        

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, OUTPUT);
 
      
//Set both motors to full speed
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);

 //Make sure both motors are set to off
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
 
}

void loop() {

//Here's where the bulk of your code will go. Currently this code won't do anything after initializations. 







}

//This is a function that you can call to update the current distance value
void distanceMeasurement(){
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
 long rawDistance = pulseIn (echoPin, HIGH);
  distance = rawDistance / 29 / 2;
  Serial.println(distance);
  }
