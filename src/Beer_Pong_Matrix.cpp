/**
 * Inspiré de l'Exemple XYMatrix.ino de la librairie FastLED
*/

#include <FastLED.h>

#include "Beer_Pong_Matrix.h"

//            Matrice Layout (8x32)
//
//     0 >  1 >  2 >  3 >  4 >  5 >  6 >  7
//                                        |
//     .----<----<----<--------<----<-----'
//     |
//     8 >  9 > 10 > 11 > 12 > 13 > 14 > 15
//                                        |
//     .----<----<----<--------<----<-----'
//     |
//    16 > 17 > 18 > 19 > 20 > 21 > 22 > 23
//                                        |
//     .----<----<----<--------<----<-----'
//     |
//    +8 > +8 > +8 > +8 > +8 > +8 > +8 > +8
//                                        |
//     .----<----<----<--------<----<-----'
//     |
//                (32 lignes)
//
//  Indice à utiliser si layout différent
//  i = kMatrixHeight * (kMatrixWidth - (x+1))+y;



// XYMatrix Fonctions //

void setup_matrix(CRGB leds_matrix[]) //ToTest
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds_matrix, NUM_LEDS_MATRIX).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );
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
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i+LAST_LINE]  = CRGB :: Red;
  }
  for (int i = 9; i <= 9+LAST_LINE; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i+5]  = CRGB :: Red;
  }
}

static void print_1_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = CRGB :: Red;
  }

  leds_matrix[9+LAST_LINE]  = CRGB :: Red;
  leds_matrix[10+LAST_LINE]  = CRGB :: Red;

  for (int i = 11; i <= 11+LAST_LINE; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i+1]  = CRGB :: Red;
  }
}

static void print_2_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i+MID_LINE]  = CRGB :: Red;
    leds_matrix[i+LAST_LINE]  = CRGB :: Red;
  }

  for (int i = 14; i <= 14+MID_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = 9+MID_LINE; i <= 9+LAST_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_3_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i+MID_LINE]  = CRGB :: Red;
    leds_matrix[i+LAST_LINE]  = CRGB :: Red;
  }

  for (int i = 9; i <= 9+LAST_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_4_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i+MID_LINE]  = CRGB :: Red;
    leds_matrix[i+LAST_LINE]  = CRGB :: Red;
  }

  for (int i = 9; i <= 9+LAST_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = 14+MID_LINE; i <= 14+LAST_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_5_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i+MID_LINE]  = CRGB :: Red;
    leds_matrix[i+LAST_LINE]  = CRGB :: Red;
  }

  for (int i = 9; i <= 9+MID_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = 14+MID_LINE; i <= 14+LAST_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_6_1(CRGB leds_matrix[])
{
  for (int i = 9; i <= 14; i++)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i+MID_LINE]  = CRGB :: Red;
    leds_matrix[i+LAST_LINE]  = CRGB :: Red;
  }

  for (int i = 9; i <= 9+LAST_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = 14; i <= 14+MID_LINE ; i += NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

// Equipe 2 //

static void print_0_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i-LAST_LINE]  = CRGB :: Red;
  }
  for (int i = START_LINE_2; i >= START_LINE_2 - LAST_LINE; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i - 5]  = CRGB :: Red;
  }
}

static void print_1_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = CRGB :: Red;
  }

  leds_matrix[START_LINE_2 - LAST_LINE]  = CRGB :: Red;
  leds_matrix[START_LINE_2 - LAST_LINE - 1]  = CRGB :: Red;

  for (int i = START_LINE_2 - 2; i >= START_LINE_2 - 2 - LAST_LINE; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i-1]  = CRGB :: Red;
  }
}

static void print_2_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i-MID_LINE]  = CRGB :: Red;
    leds_matrix[i-LAST_LINE]  = CRGB :: Red;
  }

  for (int i = COLUMN_2; i >= COLUMN_2-MID_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = START_LINE_2-MID_LINE; i >= START_LINE_2-LAST_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_3_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i-MID_LINE]  = CRGB :: Red;
    leds_matrix[i-LAST_LINE]  = CRGB :: Red;
  }

  for (int i = START_LINE_2; i >= START_LINE_2-LAST_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_4_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i-MID_LINE]  = CRGB :: Red;
    leds_matrix[i-LAST_LINE]  = CRGB :: Red;
  }

  for (int i = START_LINE_2; i >= START_LINE_2-LAST_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = COLUMN_2-MID_LINE; i <= COLUMN_2-LAST_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_5_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i-MID_LINE]  = CRGB :: Red;
    leds_matrix[i-LAST_LINE]  = CRGB :: Red;
  }

  for (int i = START_LINE_2; i >= START_LINE_2-MID_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = COLUMN_2-MID_LINE; i >= COLUMN_2-LAST_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

static void print_6_2(CRGB leds_matrix[])
{
  for (int i = START_LINE_2; i >= COLUMN_2; i--)
  {
    leds_matrix[i]  = CRGB :: Red;
    leds_matrix[i-MID_LINE]  = CRGB :: Red;
    leds_matrix[i-LAST_LINE]  = CRGB :: Red;
  }

  for (int i = START_LINE_2; i >= START_LINE_2-LAST_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
  for (int i = COLUMN_2; i >= COLUMN_2-MID_LINE ; i -= NEXT_LINE)
  {
    leds_matrix[i]  = CRGB :: Red;
  }
}

void clear_matrix(CRGB leds_matrix[])
{
  for (int i = 0; i < NUM_LEDS_MATRIX; i++)
  {
    leds_matrix[i]  = CRGB :: Blue;
  }
}

void print_score(uint8_t score_1, uint8_t score_2, CRGB leds_matrix[]) //ToTest
{
  // Reset de la matrice de Bleu //
  for (int i = 0; i < NUM_LEDS_MATRIX; i++)
  {
    leds_matrix[i]  = CRGB :: Blue;
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
    leds_matrix[i]  = CRGB :: Red;
  }
  leds_matrix[start_idx + NEXT_LINE]  = CRGB :: Red;
  for (int i = start_idx + 2*NEXT_LINE; i < start_idx + 2*NEXT_LINE + 5; i++)
  {
    leds_matrix[i]  = CRGB :: Red;
  }

  // S
  for (int i = start_idx + 4*NEXT_LINE; i < start_idx + 4*NEXT_LINE + 5; i+=2)
  {
    for (int j = 0; i < 3; j++)
    {
      leds_matrix[i+j]  = CRGB :: Red;
    }
  }
  leds_matrix[start_idx + 4*NEXT_LINE + 4]  = CRGB :: Red;
  leds_matrix[start_idx + 6*NEXT_LINE + 4]  = CRGB :: Red;

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
    //   leds_matrix[i+j]  = CRGB :: Red;
    // }
    // FastLED.show();
  }
}