#include "config.h"
#include "display/ws2812.h"
#include "animations/rainbow.h"
#include "animations/wipe.h"
#include "animations/sparkle.h"
#include "sensors/ultrasonic.h"
#include "sound/buzzer.h"

unsigned long lastTriggerMs = 0;
bool lockedOut = false;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  leds_init();
  leds_fill(CRGB::Black);
  
  Serial.println("Grocery Checkout System Ready");
}

void loop() {
  unsigned long now = millis();
  unsigned int cm = read_distance_cm();

  if (!lockedOut && cm < SCAN_THRESHOLD_CM) {
    lockedOut = true;
    
    Serial.print("Item scanned! Distance: ");
    Serial.print(cm);
    Serial.println(" cm");

    // Visual + sound feedback
    beep();
    anim_wipe(CRGB::Yellow, 6);
    anim_rainbow(1, 4);
    anim_sparkle(CRGB::Green, 300);
    leds_fill(CRGB::Black);

    lastTriggerMs = now;
  }

  if (lockedOut && (now - lastTriggerMs) > SCAN_COOLDOWN_MS) {
    lockedOut = false;
  }

  delay(20);
}