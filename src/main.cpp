#ifdef RUN_ARDUINO
  #include <Arduino.h>
  #include <FastLED.h>
#elif RUN_TEST
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define CRGB int
  #define uint8_t int
#endif

#include "Beer_Pong_Matrix.h"
#include "Beer_Pong_Strip.h"

// Equipes //
#define EQUIPE_1 1
#define EQUIPE_2 2

// Capteurs //
#define START_SENSOR DATA_PIN + 1
#define NUM_SENSOR 12
#define BAUD 9600
#define RANGE 650

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
#ifdef RUN_ARDUINO
void test_sensor(int sensor_pin)
{
  Serial.print("test_sensor: ");
  Serial.println(digitalRead(sensor_pin));
}

void read_sensors(CRGB leds_matrix[], CRGB leds_strip[])
{
  uint8_t count_1 = 0;
  uint8_t count_2 = 0;

  for (int i = 0; i < NUM_SENSOR/2; i++)
  {
    // Compte des capteurs recouvert Equipe 1 //
    if(digitalRead(i + START_SENSOR) == 0) 
    {
      count_1++;
    }
  }
  for (int i = (NUM_SENSOR/2); i < NUM_SENSOR; i++)
  {
    // Compte des capteurs recouvert Equipe 2 //
    if(digitalRead(i + START_SENSOR) == 0)
    {
      count_2++;
    }
  }

  // Comparaison Capteurs recouverts avec score pour mettre à jour //
  if ((count_1 + count_2) < (score_1 + score_2))
  {
    print_US(leds_matrix, COlOR_1);
  }
  score_1 = count_1;
  score_2 = count_2;
}


void setup() {
  // Init Com Capteurs //
  Serial.begin(BAUD);
  Serial.print("Hello World\n");
  // LED Init //
  setup_matrix(leds_matrix);
  setup_strip(leds_strip);
  // Print US //
  print_US(leds_matrix, COlOR_1);       
}

void loop() {
  delay(500);
  strip_ambient(leds_strip, COlOR_1, COlOR_2);
  read_sensors(leds_matrix, leds_strip);
  clear_matrix(leds_matrix, COlOR_2);
  print_score(score_1, score_2, leds_matrix);
}

#elif RUN_TEST

int main()
{
  printf("\n\n");
  
  for (size_t i = 0; i < 26; i++)
  {
    print_letter('A' + i, 0, leds_matrix, COlOR_1);
    simu_matrix(leds_matrix);

    clear_matrix(leds_matrix, COlOR_2);
    printf("\n\n");
  }

  printf("\n\n");
  return 0;
}

#endif