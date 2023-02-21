#include <Arduino.h>
#include <FastLED.h>

#include "Beer_Pong_Matrix.h"
#include "Beer_Pong_Strip.h"

// Equipes //
#define EQUIPE_1 1
#define EQUIPE_2 2

// Leds //
CRGB leds_strip[NUM_LEDS_STRIP];
CRGB leds_matrix[ NUM_LEDS_MATRIX ];

// Scores //
uint8_t score_1 = 6;
uint8_t score_2 = 6;

void setup() {
  setup_strip(leds_strip);
  setup_matrix(leds_matrix);
}

void loop() { 
  strip_animation(leds_strip);
  print_score(score_1, score_2, leds_matrix);

  // Si un verre est retiré 
  if(0)
    matrix_animation(leds_matrix);
}