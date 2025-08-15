#pragma once

// Ultrasonic
#define PIN_TRIG 2
#define PIN_ECHO 3
#define SCAN_THRESHOLD_CM 10
#define SCAN_COOLDOWN_MS 1000

// Buzzer
#define PIN_BUZZER 9
#define BEEP_MS 120

// WS2812B
#define PIN_LEDS 6
#define PANEL_W 16
#define PANEL_H 16
#define NUM_LEDS (PANEL_W * PANEL_H)
#define MAX_BRIGHTNESS 60  // 0-255; keep conservative for power

// Behavior
#define ANIMATION_DWELL_MS 800