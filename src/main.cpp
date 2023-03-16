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
uint8_t score_1 = 6;
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
  uint8_t count_1 = 0;
  uint8_t count_2 = 0;

  for (int i = 0; i <= NUM_SENSOR/2; i++)
  {
    // Compte des capteurs recouvert Equipe 1 //
    if(analogRead(A0 + i) > 570)
    {
      count_1++;
      // Serial.println("Equipe 1");
      // Serial.println(analogRead(A0 + i));
    }
  }
  // for (int i = (NUM_SENSOR/2)+1; i <= NUM_SENSOR; i++)
  // {
  //   // Compte des capteurs recouvert Equipe 2 //
  //   if(analogRead(A0 + i) > 570)
  //   {
  //     count_2++;
  //     // Serial.println("Equipe 2");
  //     // Serial.println(analogRead(A0 + i));
  //   }
  // }

  if(count_1 > 1) count_1 = 1; // Pour les test
  Serial.println(analogRead(A2));

  // Comparaison Capteurs recouverts avec score pour mettre à jour //
  if ((count_1 + count_2) < (score_1 + score_2))
  {
    // strip_animation(leds_strip);
    matrix_animation_serpent(leds_matrix, COlOR_1);
    // matrix_animation_ligne(leds_matrix, COlOR_2, COlOR_1);
    print_US(leds_matrix, COlOR_1);
  }
  score_1 = count_1;
  score_2 = count_2;
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
  // Serial.print("Score 1: ");
  // Serial.println(score_1);
  // Serial.print("Score 2: ");
  // Serial.println(score_2);

  read_sensors(leds_matrix, leds_strip);
  clear_matrix(leds_matrix, COlOR_2);
  print_score(score_1, score_2, leds_matrix);
  delay(1000);                                //Necessaire !! (à voir si on peut réduire le temps)
}
