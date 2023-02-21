#include <Arduino.h>
#include <FastLED.h>

#include "Beer_Pong_Matrix.h"
#include "Beer_Pong_Strip.h"

// Leds //
CRGB leds_strip[NUM_LEDS_STRIP];

// Equipes //
#define EQUIPE_1 1
#define EQUIPE_2 2

// Scores //
uint8_t score_1 = 6;
uint8_t score_2 = 6;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds_strip, NUM_LEDS_STRIP);
  setup_strip(leds_strip);
  setup_matrix();
}

void loop() { 
  strip_animation(leds_strip);
  print_score(score_1, score_2);
}