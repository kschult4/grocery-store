#include "config.h"
#include "display/ws2812.h"
#include "animations/rainbow.h"
#include "animations/wipe.h"
#include "animations/sparkle.h"
#include "sensors/ir_break_beam.h"
#include "sound/buzzer.h"

unsigned long lastTriggerMs = 0;
bool lockedOut = false;

void setup() {
  Serial.begin(115200);
  ir_beam_init();
  pinMode(PIN_BUZZER, OUTPUT);

  leds_init();
  leds_fill(CRGB::Black);
  
  Serial.println("Grocery Checkout System Ready");
}

void loop() {
  unsigned long now = millis();
  if (!lockedOut && is_beam_broken()) {
    lockedOut = true;
    
    Serial.println("Item scanned! Beam broken");

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