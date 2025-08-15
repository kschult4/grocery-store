#pragma once
#include "../config.h"

static unsigned long lastBeamBreakMs = 0;
static bool lastBeamState = HIGH;

inline void ir_beam_init() {
  pinMode(PIN_IR_BEAM, INPUT_PULLUP);
}

inline bool is_beam_broken() {
  static bool beamBroken = false;
  bool currentState = digitalRead(PIN_IR_BEAM);
  unsigned long now = millis();
  
  // Debounce the input
  if (currentState != lastBeamState && (now - lastBeamBreakMs) > DEBOUNCE_MS) {
    lastBeamState = currentState;
    lastBeamBreakMs = now;
    
    // LOW = beam broken (item detected)
    if (currentState == LOW && !beamBroken) {
      beamBroken = true;
      return true;
    }
    // HIGH = beam restored (item passed through)
    else if (currentState == HIGH && beamBroken) {
      beamBroken = false;
    }
  }
  
  return false;
}