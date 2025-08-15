#pragma once
#include "../config.h"

inline void beep(unsigned long ms = BEEP_MS) {
  digitalWrite(PIN_BUZZER, HIGH);
  delay(ms);
  digitalWrite(PIN_BUZZER, LOW);
}