#pragma once
#include <FastLED.h>
#include "../config.h"

static CRGB leds[NUM_LEDS];

inline void leds_init() {
  FastLED.addLeds<WS2812B, PIN_LEDS, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(MAX_BRIGHTNESS);
  FastLED.clear(true);
}

inline void leds_show() { FastLED.show(); }

inline int xy(int x, int y) {
  // serpentine mapping (adjust if your panel is wired differently)
  if (y % 2 == 0) return y * PANEL_W + x;
  else return y * PANEL_W + (PANEL_W - 1 - x);
}

inline void leds_fill(CRGB c) {
  fill_solid(leds, NUM_LEDS, c);
  leds_show();
}