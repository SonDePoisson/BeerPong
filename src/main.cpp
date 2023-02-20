#include <Arduino.h>
#include <FastLED.h>

#include "Beer_Pong_Matrix.h"
#include "Beer_Pong_Strip.h"

#define NUM_LEDS_STRIP 1
#define DATA_PIN 3

// Leds //
CRGB leds[NUM_LEDS_STRIP];


void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS_STRIP);
  // setup_strip(leds);
  // setup_matrix();
}

void loop() { 
  // strip_animation(leds);
}