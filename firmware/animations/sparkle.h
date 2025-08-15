#pragma once
#include <FastLED.h>
#include "../config.h"
#include "../display/ws2812.h"

inline void anim_sparkle(CRGB color = CRGB::White, int duration = 800) {
  unsigned long startTime = millis();
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  
  while (millis() - startTime < duration) {
    int pos = random(NUM_LEDS);
    leds[pos] = color;
    leds_show();
    delay(50);
    leds[pos] = CRGB::Black;
  }
  
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  leds_show();
}