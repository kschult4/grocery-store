#pragma once
#include <FastLED.h>
#include "../config.h"
#include "../display/ws2812.h"

inline void anim_wipe(CRGB color = CRGB::White, int stepDelay = 10) {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for (int y = 0; y < PANEL_H; y++) {
    for (int x = 0; x < PANEL_W; x++) {
      leds[xy(x,y)] = color;
    }
    leds_show();
    delay(stepDelay);
  }
}