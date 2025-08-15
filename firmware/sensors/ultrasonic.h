#pragma once
#include <NewPing.h>
#include "../config.h"

static NewPing sonar(PIN_TRIG, PIN_ECHO, 200);

inline unsigned int read_distance_cm() {
  unsigned int cm = sonar.ping_cm();
  return cm == 0 ? 999 : cm;
}