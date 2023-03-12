/**
 * Inspiré de l'Exemple XYMatrix.ino de la librairie FastLED
*/

#include <FastLED.h>

#include "Beer_Pong_Matrix.h"

// XYMatrix Fonctions //

void setup_matrix(CRGB leds_matrix[]) //ToTest
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds_matrix, NUM_LEDS_MATRIX).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );
  clear_matrix(leds_matrix);
  FastLED.show();
}

unsigned long getLed(int x, int y) {
  return (y + (y % 2)) * WIDTH + (2 * ((y + 1) % 2) - 1) * (x + (y % 2));
} 

// Scores //
/**
 * Affiche le score de la :
 * - ligne 1 à 14
 * - colone 1 à 6
 * (Commence à la ligne/colone 0)
 * 
 * 2 boucles for a chaque fois pour afficher
 * la ligne puis la colone (comme un 7_segment):
 * - MID_LINE est le segment du milieu
 * _ LAST_LINE est le segment du haut (le plus
 *   loin du bord de la table)
*/

// Equipe 1 //

static void print_0_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i+LAST_LINE]  = COlOR_1;
    leds_matrix[i + NEXT_LINE]  = COlOR_1;
    leds_matrix[i + NEXT_LINE+LAST_LINE]  = COlOR_1;
  }
  for (int i = 0; i <= 10; i+= 2)
  {
    leds_matrix[COLUMN_1+SHORT_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+LONG_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+SHORT_CORNER+i*NEXT_LINE+1]  = COlOR_1;
    leds_matrix[COLUMN_1+LONG_CORNER+i*NEXT_LINE-1]  = COlOR_1;
  }
  for (int i = 0; i <= 5; i++)
  {
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER+1]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER-1]  = COlOR_1;
  }
}

static void print_1_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i+NEXT_LINE]  = COlOR_1;
  }
  leds_matrix[LAST_LINE + COLUMN_1]  = COlOR_1;
  leds_matrix[LAST_LINE + COLUMN_1 - 1]  = COlOR_1;
  leds_matrix[LAST_LINE + NEXT_LINE + COLUMN_1 - 5]  = COlOR_1;
  leds_matrix[LAST_LINE + NEXT_LINE + COLUMN_1 - 4]  = COlOR_1;

  for (int i = 11; i <= 11 + LAST_LINE + NEXT_LINE; i += NEXT_LINE)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i+1]  = COlOR_1;
  }
}

static void print_2_1(CRGB leds_matrix[])
{
  for (int i = START_LINE_1; i <= COLUMN_1; i++)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i+MID_LINE]  = COlOR_1;
    leds_matrix[i+LAST_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE+MID_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE+LAST_LINE]  = COlOR_1;
  }

  for (int i = 0; i <= 5; i+= 2)
  {
    leds_matrix[COLUMN_1+SHORT_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+LONG_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+SHORT_CORNER+i*NEXT_LINE+1]  = COlOR_1;
    leds_matrix[COLUMN_1+LONG_CORNER+i*NEXT_LINE-1]  = COlOR_1;
  }
  for (int i = 0; i <= 2; i++)
  {
    leds_matrix[START_LINE_1+MID_LINE+(i+1)*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+MID_LINE+13+i*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+MID_LINE+(i+1)*LONG_CORNER+1]  = COlOR_1;
    leds_matrix[START_LINE_1+MID_LINE+13+i*LONG_CORNER-1]  = COlOR_1;
  }
}

static void print_3_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i+MID_LINE]  = COlOR_1;
    leds_matrix[i+LAST_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE+MID_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE+LAST_LINE]  = COlOR_1;
  }

  for (int i = 0; i <= 5; i++)
  {
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER+1]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER-1]  = COlOR_1;
  }
}

static void print_4_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i+MID_LINE]  = COlOR_1;
    leds_matrix[i+MID_LINE+NEXT_LINE]  = COlOR_1;
  }

  for (int i = 1; i < 15; i++)
  {
    leds_matrix[getLed(5, i)] = COlOR_1;
    leds_matrix[getLed(6, i)] = COlOR_1;
  }
  for (int i = 8; i < 15; i++)
  {
    leds_matrix[getLed(1, i)] = COlOR_1;
    leds_matrix[getLed(2, i)] = COlOR_1;
  }
  
}

static void print_5_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i+MID_LINE]  = COlOR_1;
    leds_matrix[i+LAST_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE]  = COlOR_1;
    leds_matrix[i+MID_LINE+NEXT_LINE]  = COlOR_1;
    leds_matrix[i+LAST_LINE+NEXT_LINE]  = COlOR_1;
  }

  for (int i = 0; i <= 5; i+= 2)
  {
    leds_matrix[COLUMN_1+MID_LINE+SHORT_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+MID_LINE+LONG_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+MID_LINE+SHORT_CORNER+i*NEXT_LINE+1]  = COlOR_1;
    leds_matrix[COLUMN_1+MID_LINE+LONG_CORNER+i*NEXT_LINE-1]  = COlOR_1;
  }
  for (int i = 0; i <= 2; i++)
  {
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER+1]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER-1]  = COlOR_1;
  }
}

static void print_6_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i+MID_LINE]  = COlOR_1;
    leds_matrix[i+LAST_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE+MID_LINE]  = COlOR_1;
    leds_matrix[i+NEXT_LINE+LAST_LINE]  = COlOR_1;
  }

  for (int i = 0; i <= 10; i+= 2)
  {
    leds_matrix[COLUMN_1+SHORT_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+LONG_CORNER+i*NEXT_LINE]  = COlOR_1;
    leds_matrix[COLUMN_1+SHORT_CORNER+i*NEXT_LINE+1]  = COlOR_1;
    leds_matrix[COLUMN_1+LONG_CORNER+i*NEXT_LINE-1]  = COlOR_1;
  }
  for (int i = 0; i <= 2; i++)
  {
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER]  = COlOR_1;
    leds_matrix[START_LINE_1+(i+1)*LONG_CORNER+1]  = COlOR_1;
    leds_matrix[START_LINE_1+13+i*LONG_CORNER-1]  = COlOR_1;
  }
}

// Equipe 2 //

static void print_0_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i - LAST_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE - LAST_LINE]  = COlOR_1;
  }
  
  for (int i = 1; i <= 6; i++)
  {
    leds_matrix[START_LINE_2 - i*LONG_CORNER] = COlOR_1;
    leds_matrix[START_LINE_2 - i*LONG_CORNER + SHORT_CORNER] = COlOR_1;
    leds_matrix[START_LINE_2 - i*LONG_CORNER -1] = COlOR_1;
    leds_matrix[START_LINE_2 - i*LONG_CORNER + SHORT_CORNER +1] = COlOR_1;
  }

  for (size_t i = 17; i < 29; i++)
  {
    leds_matrix[getLed(1, i)] = COlOR_1;
    leds_matrix[getLed(2, i)] = COlOR_1;
  }
}

static void print_1_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i - NEXT_LINE]  = COlOR_1;
  }

  leds_matrix[getLed(5, 17)]  = COlOR_1;
  leds_matrix[getLed(6, 17)]  = COlOR_1;
  leds_matrix[getLed(5, 18)]  = COlOR_1;
  leds_matrix[getLed(6, 18)]  = COlOR_1;

  for (int i = 17; i < 31; i++)
  {
    leds_matrix[getLed(3, i)]  = COlOR_1;
    leds_matrix[getLed(4, i)]  = COlOR_1;
  }
  
  
}

static void print_2_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i-MID_LINE]  = COlOR_1;
    leds_matrix[i-LAST_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-MID_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-LAST_LINE]  = COlOR_1;
  }

  for (int i = 24; i < 29 ; i++)
  {
    leds_matrix[getLed(5, i)]  = COlOR_1;
    leds_matrix[getLed(6, i)]  = COlOR_1;
  }
  for (int i = 19; i < 24 ; i++)
  {
    leds_matrix[getLed(1, i)]  = COlOR_1;
    leds_matrix[getLed(2, i)]  = COlOR_1;
  }
}

static void print_3_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i - MID_LINE]  = COlOR_1;
    leds_matrix[i - LAST_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-MID_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-LAST_LINE]  = COlOR_1;
  }

  for (int i = 19; i < 29 ; i++)
  {
    leds_matrix[getLed(1, i)]  = COlOR_1;
    leds_matrix[getLed(2, i)]  = COlOR_1;
  }
  
}

static void print_4_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i-MID_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE - MID_LINE]  = COlOR_1;
  }

  for (int i = 17; i < 24 ; i++)
  {
    leds_matrix[getLed(5, i)]  = COlOR_1;
    leds_matrix[getLed(6, i)]  = COlOR_1;
  }
  for (int i = 17; i < 31 ; i++)
  {
    leds_matrix[getLed(1, i)]  = COlOR_1;
    leds_matrix[getLed(2, i)]  = COlOR_1;
  }
}

static void print_5_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i-MID_LINE]  = COlOR_1;
    leds_matrix[i-LAST_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-MID_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-LAST_LINE]  = COlOR_1;
  }

  for (int i = 24; i < 29 ; i++)
  {
    leds_matrix[getLed(1, i)]  = COlOR_1;
    leds_matrix[getLed(2, i)]  = COlOR_1;
  }
  for (int i = 19; i < 24 ; i++)
  {
    leds_matrix[getLed(5, i)]  = COlOR_1;
    leds_matrix[getLed(6, i)]  = COlOR_1;
  }
}

static void print_6_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = COlOR_1;
    leds_matrix[i-MID_LINE]  = COlOR_1;
    leds_matrix[i-LAST_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-MID_LINE]  = COlOR_1;
    leds_matrix[i - NEXT_LINE-LAST_LINE]  = COlOR_1;
  }

  for (int i = 19; i < 29 ; i++)
  {
    leds_matrix[getLed(5, i)]  = COlOR_1;
    leds_matrix[getLed(6, i)]  = COlOR_1;
  }  
  for (int i = 24; i < 29 ; i++)
  {
    leds_matrix[getLed(1, i)]  = COlOR_1;
    leds_matrix[getLed(2, i)]  = COlOR_1;
  }  
}

void clear_matrix(CRGB leds_matrix[])
{
  for (int i = 0; i < NUM_LEDS_MATRIX; i++)
  {
    leds_matrix[i]  = COlOR_2;
  }
}

void print_score(uint8_t score_1, uint8_t score_2, CRGB leds_matrix[]) //ToTest
{
  // Reset de la matrice de Bleu //
  for (int i = 0; i < NUM_LEDS_MATRIX; i++)
  {
    leds_matrix[i]  = COlOR_2;
  }
  
  // Score Equipe 2 //
  switch (score_1)
  {
  case 0:
    print_0_1(leds_matrix);
      break;

  case 1:
    print_1_1(leds_matrix);
      break;
      
  case 2:
    print_2_1(leds_matrix);
      break;
      
  case 3:
    print_3_1(leds_matrix);
      break;
      
  case 4:
    print_4_1(leds_matrix);
      break;
      
  case 5:
    print_5_1(leds_matrix);
      break;
      
  case 6:
    print_6_1(leds_matrix);
      break;
  default:
      break;
  }
  // Score Equipe 2 //
  switch (score_2)
  {
  case 0:
    print_0_2(leds_matrix);
      break;

  case 1:
    print_1_2(leds_matrix);
      break;
      
  case 2:
    print_2_2(leds_matrix);
      break;
      
  case 3:
    print_3_2(leds_matrix);
      break;
      
  case 4:
    print_4_2(leds_matrix);
      break;
      
  case 5:
    print_5_2(leds_matrix);
      break;
      
  case 6:
    print_6_2(leds_matrix);
      break;
  default:
      break;
  }
  FastLED.show();
}

void print_US(CRGB leds_matrix[], int start_idx)
{
  // U
  for (int i = start_idx; i < start_idx + 5; i++)
  {
    leds_matrix[i]  = COlOR_1;
  }
  leds_matrix[start_idx + NEXT_LINE]  = COlOR_1;
  for (int i = start_idx + 2*NEXT_LINE; i < start_idx + 2*NEXT_LINE + 5; i++)
  {
    leds_matrix[i]  = COlOR_1;
  }

  // S
  for (int i = start_idx + 4*NEXT_LINE; i < start_idx + 4*NEXT_LINE + 5; i+=2)
  {
    for (int j = 0; i < 3; j++)
    {
      leds_matrix[i+j]  = COlOR_1;
    }
  }
  leds_matrix[start_idx + 4*NEXT_LINE + 4]  = COlOR_1;
  leds_matrix[start_idx + 6*NEXT_LINE + 4]  = COlOR_1;

  // Print
  FastLED.show();
}

void matrix_animation(CRGB leds_matrix[])
{

  for (int i = 0; i < NUM_LEDS_MATRIX; i+=8)  //Effet Balayage
  {

    clear_matrix(leds_matrix);
    print_US(leds_matrix, i);
    delay(100);

    // for (int j = 0; j < 8; i++)
    // {
    //   leds_matrix[i+j]  = COlOR_1;
    // }
    // FastLED.show();
  }
}