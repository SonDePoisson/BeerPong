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
CRGB leds_matrix[NUM_LEDS_MATRIX];

// Scores //
uint8_t score_1 = 0;
uint8_t score_2 = 6;


// Sensors Functions //
/**
 * Lis le nombre de capteur retournant une valeur 
 * Compare au score affiché
 * S'il est différent :
 * - affiche les animations
 * - met à jour le score
*/
void read_sensors(CRGB leds_matrix[], CRGB leds_strip[])
{
  uint8_t count = 0;

  for (int i = 0; i < NUM_SENSOR; i++)
  {
    // Compte des capteurs recouvert //
    if((analogRead(A0 + i) > 0) && (analogRead(A0 + i) < 256))
    {
      count++;
    }
    // Comparaison Capteurs recouverts avec score pour mettre à jour //
    if (count < (score_1 + score_2))
    {
      strip_animation(leds_strip);
      matrix_animation_serpent(leds_matrix, COlOR_1);
      if (i < NUM_SENSOR/2)
        score_1--;
      else
        score_2--;
    }
    count = 0;
  }
}

// Main //
void setup() {
  // Init Com Capteurs //
  Serial.begin(BAUD);
  Serial.print("Hello World\n");
  // LED Init //
  setup_strip(leds_strip);
  setup_matrix(leds_matrix);
  // Print US //
  // print_US(leds_matrix, COlOR_1);
}

void loop() {
  // Serial.print("Testing connection\n");
  // delay(1000);
  // clear_matrix(leds_matrix);
  // print_score(score_1, score_2, leds_matrix);
  // delay(3000);
  // score_1++;
  // score_2--;
  // if (score_1 > 6)
  // {
  //   score_1 = 0;
  //   score_2 = 6;
  // } 
  // print_US(leds_matrix, COlOR_1);
  matrix_animation_serpent(leds_matrix, COlOR_1);
  matrix_animation_ligne(leds_matrix, COlOR_2, COlOR_1);
  // strip_ambient(leds_strip);
  // read_sensors(leds_matrix, leds_strip);
}
