#include <FastLED.h>
#define PIN_LEDS 6
#define NUM_LEDS 256
#define BRIGHT 40
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, PIN_LEDS, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHT);
  Serial.begin(115200);
  Serial.println("LED Test Starting...");
}

void loop() {
  Serial.println("Red");
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  delay(500);
  
  Serial.println("Green");
  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
  delay(500);
  
  Serial.println("Blue");
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  delay(500);
  
  Serial.println("Off");
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(500);
}