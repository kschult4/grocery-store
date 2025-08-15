#pragma once
#include <FastLED.h>
#include "../config.h"
#include "../display/ws2812.h"

inline void anim_rainbow(uint8_t cycles = 1, uint8_t stepDelay = 8) {
  for (int j = 0; j < 256 * cycles; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV((i * 256 / NUM_LEDS + j) & 255, 255, 255);
    }
    leds_show();
    delay(stepDelay);
  }
}