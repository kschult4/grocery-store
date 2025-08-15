#include <NewPing.h>

#define PIN_TRIG 2
#define PIN_ECHO 3
#define MAX_DISTANCE 200

NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
  Serial.println("Ultrasonic Sensor Test Starting...");
}

void loop() {
  unsigned int distance = sonar.ping_cm();
  
  if (distance == 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    if (distance < 10) {
      Serial.println("*** SCAN DETECTED ***");
    }
  }
  
  delay(100);
}