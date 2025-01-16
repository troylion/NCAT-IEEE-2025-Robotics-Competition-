/*
 * Modified to support 6 ultrasonic sensors.
 * Based on code from https://randomnerdtutorials.com
 * Original by http://playground.arduino.cc/Code/NewPing
 */

#include <NewPing.h>

// Define the number of sensors
#define NUM_SENSORS 6

// Define trigger and echo pins for each sensor
const int triggerPins[NUM_SENSORS] = {2, 4, 6, 8, 10, 12};
const int echoPins[NUM_SENSORS] = {3, 5, 7, 9, 11, 13};

// Define maximum distance for each sensor
#define MAX_DISTANCE 200

// Create an array of NewPing objects
NewPing sonar[NUM_SENSORS] = {
  NewPing(triggerPins[0], echoPins[0], MAX_DISTANCE),
  NewPing(triggerPins[1], echoPins[1], MAX_DISTANCE),
  NewPing(triggerPins[2], echoPins[2], MAX_DISTANCE),
  NewPing(triggerPins[3], echoPins[3], MAX_DISTANCE),
  NewPing(triggerPins[4], echoPins[4], MAX_DISTANCE),
  NewPing(triggerPins[5], echoPins[5], MAX_DISTANCE)
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    delay(50); // Short delay between sensor readings
    unsigned int distance = sonar[i].ping_cm();
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(distance / 2.54); // Convert cm to inches
    Serial.println(" Inches");
  }
}
