/**
 * Inspiré de l'Exemple XYMatrix.ino de la librairie FastLED
*/

#ifdef RUN_ARDUINO
  #include <FastLED.h>
#elif RUN_TEST
  #include <stdio.h>
  #include <string.h>
  #define CRGB int
  #define uint8_t int
#endif

#include "Beer_Pong_Matrix.h"

#ifdef RUN_ARDUINO
long couleurs[148] = 
{
  CRGB::AliceBlue,
  CRGB::Amethyst,
  CRGB::AntiqueWhite,
  CRGB::Aqua,
  CRGB::Aquamarine,
  CRGB::Azure,
  CRGB::Beige,
  CRGB::Bisque,
  CRGB::Black,
  CRGB::BlanchedAlmond,
  CRGB::Blue,
  CRGB::BlueViolet,
  CRGB::Brown,
  CRGB::BurlyWood,
  CRGB::CadetBlue,
  CRGB::Chartreuse,
  CRGB::Chocolate,
  CRGB::Coral,
  CRGB::CornflowerBlue,
  CRGB::Cornsilk,
  CRGB::Crimson,
  CRGB::Cyan,
  CRGB::DarkBlue,
  CRGB::DarkCyan,
  CRGB::DarkGoldenrod,
  CRGB::DarkGray,
  CRGB::DarkGrey,
  CRGB::DarkGreen,
  CRGB::DarkKhaki,
  CRGB::DarkMagenta,
  CRGB::DarkOliveGreen,
  CRGB::DarkOrange,
  CRGB::DarkOrchid,
  CRGB::DarkRed,
  CRGB::DarkSalmon,
  CRGB::DarkSeaGreen,
  CRGB::DarkSlateBlue,
  CRGB::DarkSlateGray,
  CRGB::DarkSlateGrey,
  CRGB::DarkTurquoise,
  CRGB::DarkViolet,
  CRGB::DeepPink,
  CRGB::DeepSkyBlue,
  CRGB::DimGray,
  CRGB::DimGrey,
  CRGB::DodgerBlue,
  CRGB::FireBrick,
  CRGB::FloralWhite,
  CRGB::ForestGreen,
  CRGB::Fuchsia,
  CRGB::Gainsboro,
  CRGB::GhostWhite,
  CRGB::Gold,
  CRGB::Goldenrod,
  CRGB::Gray,
  CRGB::Grey,
  CRGB::Green,
  CRGB::GreenYellow,
  CRGB::Honeydew,
  CRGB::HotPink,
  CRGB::IndianRed,
  CRGB::Indigo,
  CRGB::Ivory,
  CRGB::Khaki,
  CRGB::Lavender,
  CRGB::LavenderBlush,
  CRGB::LawnGreen,
  CRGB::LemonChiffon,
  CRGB::LightBlue,
  CRGB::LightCoral,
  CRGB::LightCyan,
  CRGB::LightGoldenrodYellow,
  CRGB::LightGreen,
  CRGB::LightGrey,
  CRGB::LightPink,
  CRGB::LightSalmon,
  CRGB::LightSeaGreen,
  CRGB::LightSkyBlue,
  CRGB::LightSlateGray,
  CRGB::LightSlateGrey,
  CRGB::LightSteelBlue,
  CRGB::LightYellow,
  CRGB::Lime,
  CRGB::LimeGreen,
  CRGB::Linen,
  CRGB::Magenta,
  CRGB::Maroon,
  CRGB::MediumAquamarine,
  CRGB::MediumBlue,
  CRGB::MediumOrchid,
  CRGB::MediumPurple,
  CRGB::MediumSeaGreen,
  CRGB::MediumSlateBlue,
  CRGB::MediumSpringGreen,
  CRGB::MediumTurquoise,
  CRGB::MediumVioletRed,
  CRGB::MidnightBlue,
  CRGB::MintCream,
  CRGB::MistyRose,
  CRGB::Moccasin,
  CRGB::NavajoWhite,
  CRGB::Navy,
  CRGB::OldLace,
  CRGB::Olive,
  CRGB::OliveDrab,
  CRGB::Orange,
  CRGB::OrangeRed,
  CRGB::Orchid,
  CRGB::PaleGoldenrod,
  CRGB::PaleGreen,
  CRGB::PaleTurquoise,
  CRGB::PaleVioletRed,
  CRGB::PapayaWhip,
  CRGB::PeachPuff,
  CRGB::Peru,
  CRGB::Pink,
  CRGB::Plaid,
  CRGB::Plum,
  CRGB::PowderBlue,
  CRGB::Purple,
  CRGB::Red,
  CRGB::RosyBrown,
  CRGB::RoyalBlue,
  CRGB::SaddleBrown,
  CRGB::Salmon,
  CRGB::SandyBrown,
  CRGB::SeaGreen,
  CRGB::Seashell,
  CRGB::Sienna,
  CRGB::Silver,
  CRGB::SkyBlue,
  CRGB::SlateBlue,
  CRGB::SlateGray,
  CRGB::SlateGrey,
  CRGB::Snow,
  CRGB::SpringGreen,
  CRGB::SteelBlue,
  CRGB::Tan,
  CRGB::Teal,
  CRGB::Thistle,
  CRGB::Tomato,
  CRGB::Turquoise,
  CRGB::Violet,
  CRGB::Wheat,
  CRGB::White,
  CRGB::WhiteSmoke,
  CRGB::Yellow,
  CRGB::YellowGreen
};
#endif

// XYMatrix Fonctions //

#ifdef RUN_TEST
// Simule la matrice led //
void simu_matrix(CRGB leds_matrix[])
{ 
  for (int i = 0; i < WIDTH; i++)
  {
    for (int j = 0; j < HIGH_MATRIX; j++)
    {
      if (leds_matrix[getLed(i, j)] == COlOR_1)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
}
#endif

void setup_matrix(CRGB leds_matrix[]) //ToTest
{
  #ifdef RUN_ARDUINO
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds_matrix, NUM_LEDS_MATRIX).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );
  clear_matrix(leds_matrix, COlOR_2);
  FastLED.show();
  #endif
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

  for (int i = 17; i < 29; i++)
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

void clear_matrix(CRGB leds_matrix[], long color)
{
  for (int i = 0; i < NUM_LEDS_MATRIX; i++)
  {
    leds_matrix[i]  = color;
  }
}

void print_score(uint8_t score_1, uint8_t score_2, CRGB leds_matrix[])
{
  // Reset de la matrice de Bleu //
  clear_matrix(leds_matrix, COlOR_2);
  
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

  #ifdef RUN_ARDUINO
    FastLED.show();
  #endif
}



// ANIMATION //

const bool letter_pixels[26][8][8] = {
    // définition de la lettre A 
    {{0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0}},

    // définition de la lettre B
    {{0, 1, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 0, 0}},

    // définition de la lettre C
    {{0, 0, 0, 1, 1, 1, 0, 0},
     {0, 0, 1, 1, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 0, 1, 1, 0, 1, 1, 0},
     {0, 0, 0, 1, 1, 1, 0, 0}},

    // définition de la lettre D
    {{0, 1, 1, 1, 1, 0, 0, 0},
     {0, 1, 1, 0, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 1, 1, 0, 0},
     {0, 1, 1, 1, 1, 0, 0, 0}},

    // définition de la lettre E
    {{0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0}},

    // définition de la lettre F
    {{0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0}},

    // définition de la lettre G
    {{0, 0, 0, 1, 1, 1, 0, 0},
     {0, 0, 1, 1, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 1, 1, 1, 0},
     {0, 1, 1, 0, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 0, 1, 0},
     {0, 0, 1, 1, 0, 1, 1, 0},
     {0, 0, 0, 1, 1, 1, 0, 0}},

    // définition de la lettre H
    {{0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0}},

    // définition de la lettre I
    {{0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0}},

    // définition de la lettre J
    {{0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 1, 1, 1, 1, 0, 0, 0},
     {0, 1, 1, 1, 0, 0, 0, 0}},

    // définition de la lettre K
    {{0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 1, 1, 0, 0},
     {0, 1, 1, 1, 1, 0, 0, 0},
     {0, 1, 1, 1, 1, 0, 0, 0},
     {0, 1, 1, 0, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0}},

    // définition de la lettre L
    {{0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0}},
  
    // définition de la lettre M
    {{0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 0, 1, 1, 0, 1, 0},
     {0, 1, 0, 1, 1, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0}},

    // définition de la lettre N
    {{0, 1, 1, 0, 0, 0, 1, 0},
     {0, 1, 1, 1, 0, 0, 1, 0},
     {0, 1, 0, 1, 0, 0, 1, 0},
     {0, 1, 0, 1, 1, 0, 1, 0},
     {0, 1, 0, 0, 1, 0, 1, 0},
     {0, 1, 0, 0, 1, 1, 1, 0},
     {0, 1, 0, 0, 0, 1, 1, 0},
     {0, 1, 0, 0, 0, 1, 1, 0}},
  
    // définition de la lettre O
    {{0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0}},
  
    // définition de la lettre P
    {{0, 1, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0}},
  
    // définition de la lettre Q
    {{0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 1, 1, 1, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 0, 0, 1, 1, 0, 1, 0}},
  
    // définition de la lettre R
    {{0, 1, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0}},

    // définition de la lettre S
    {{0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 1, 1, 1, 0, 0},
     {0, 0, 1, 1, 1, 1, 1, 0},
     {0, 0, 0, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0}},

    // définition de la lettre T
    {{0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0}},
    
    // définition de la lettre U
    {{0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0}},

    // définition de la lettre V
    {{0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0}},

    // définition de la lettre W
    {{0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 0, 0, 0, 1, 0},
     {0, 1, 0, 1, 1, 0, 1, 0},
     {0, 1, 0, 1, 1, 0, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0}},

    // définition de la lettre X
    {{0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0}},

    // définition de la lettre Y
    {{0, 1, 1, 0, 0, 1, 1, 0},
     {0, 1, 1, 0, 0, 1, 1, 0},
     {0, 0, 1, 1, 1, 1, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0}},

    // définition de la lettre Z
    {{0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 0, 0, 0, 1, 1, 0, 0},
     {0, 0, 0, 1, 1, 0, 0, 0},
     {0, 0, 1, 1, 0, 0, 0, 0},
     {0, 1, 1, 0, 0, 0, 0, 0},
     {0, 1, 1, 1, 1, 1, 1, 0},
     {0, 1, 1, 1, 1, 1, 1, 0}}
};

void print_letter(char letter, int letter_idx, CRGB leds_matrix[], long color) {
  
  int height_letter = 8;
  int width_letter = 8;

  if (letter >= 'a' && letter <= 'z')
    letter -= 32;
  
  if (letter < 'A' || letter > 'Z')
  {
    #ifdef RUN_ARDUINO
      Serial.printn("Letter Not Found");
    #elif RUN_TEST
      printf("Letter Not Found\n");
    #endif
  }
  
  for (int i = 0; i < width_letter; i++)
  {
    for (int j = 0; j < height_letter; j++)
    {
      if (letter_pixels[letter - 'A'][i][j] == 1)
      {
        leds_matrix[getLed(i, j+ height_letter*letter_idx)] = color;
      } 
    }
  } 
}

void print_word(char word[], int start_pixel, CRGB leds_matrix[], long color)
{
  for (int i = 0; i < strlen(word); i++)
  {
    print_letter(word[i], i + 8*start_pixel, leds_matrix, color);
  }
  
  simu_matrix(leds_matrix);
}

void defil_word(char word[], CRGB leds_matrix[], long color)
{
  
}


void print_US(CRGB leds_matrix[], long color)
{
  for (int j = 0; j < 17; j++)
  {
    clear_matrix(leds_matrix, COlOR_2);
    // Lettre U //
    for (int i = 0; i < 8; i++)
    {
      leds_matrix[getLed(i, 0+j)] = color;
      leds_matrix[getLed(i, 1+j)] = color;
      leds_matrix[getLed(i, 5+j)] = color;
      leds_matrix[getLed(i, 6+j)] = color;
    }
    for (int i = 0+j; i < 7+j; i++)
    {
      leds_matrix[getLed(7, i)] = color;
      leds_matrix[getLed(6, i)] = color;
    }
    
    // Lettre S //
    leds_matrix[getLed(2, 9+j)]  = color;
    leds_matrix[getLed(2, 10+j)] = color;
    leds_matrix[getLed(5, 14+j)] = color;
    leds_matrix[getLed(5, 15+j)] = color;
    for (int i = 9+j; i < 16+j; i++)
    {
      leds_matrix[getLed(0, i)] = color;
      leds_matrix[getLed(1, i)] = color;
      leds_matrix[getLed(3, i)] = color;
      leds_matrix[getLed(4, i)] = color;
      leds_matrix[getLed(6, i)] = color;
      leds_matrix[getLed(7, i)] = color;
    }
    #ifdef RUN_ARDUINO
      FastLED.show();
      delay(150);
    #endif
  }
}


void matrix_animation_serpent(CRGB leds_matrix[], long color)
{
  clear_matrix(leds_matrix, COlOR_2);
  #ifdef RUN_ARDUINO
    FastLED.show();
  #endif
  for (int i = 0; i < NUM_LEDS_MATRIX; i++)
  {
    leds_matrix[i] = color;
    #ifdef RUN_ARDUINO
      FastLED.show();
    #endif
  }
}

void matrix_animation_ligne(CRGB leds_matrix[], long color_clear, long color_draw)
{
  clear_matrix(leds_matrix, color_clear);
  #ifdef RUN_ARDUINO
    FastLED.show();
  #endif

  for (int i = 0; i < HIGH_MATRIX+8; i++)
  {
    for (int j = 0; j < i+1; j++)
    {
      leds_matrix[(getLed(i-j, j))] = color_draw;
      #ifdef RUN_ARDUINO
        FastLED.show();
      #endif
    }
    
  }
}