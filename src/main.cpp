#include <Arduino.h>
#include <FastLED.h>

#include "Beer_Pong_Matrix.h"
#include "Beer_Pong_Strip.h"

// Equipes //
#define EQUIPE_1 1
#define EQUIPE_2 2

// Capteurs //
#define NUM_SENSOR 12
#define BAUD 9600

// Leds //
CRGB leds_strip[NUM_LEDS_STRIP];
CRGB leds_matrix[ NUM_LEDS_MATRIX ];

// Scores //
uint8_t score_1 = 6;
uint8_t score_2 = 6;
uint8_t count = 0;

void setup() {
  // LED Init //
  setup_strip(leds_strip);
  setup_matrix(leds_matrix);
  // Init Com Capteurs //
  Serial.begin(BAUD);
}

void loop() { 
  strip_animation(leds_strip);
  print_score(score_1, score_2, leds_matrix);

  // Action Capteurs //
  for (int i = 0; i < NUM_SENSOR; i++)
  {
    // Compte des capteurs recouvert //
    if(analogRead(A0 + i) != 0)
    {
      count++;
    }
    // Comparaison Capteurs recouverts avec score pour mettre à jour //
    if (count < (score_1 + score_2))
    {
      matrix_animation(leds_matrix);
      if (i < NUM_SENSOR/2)
        score_1--;
      else
        score_2--;
    }
    count = 0;
  }
  
}