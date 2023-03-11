
#define LED_PIN  3
#define NUM_LEDS_MATRIX 256

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

#define BRIGHTNESS 32 //Choose between 0 -> 64

#define MID_LINE (6*8)
#define LAST_LINE (12*8)
#define NEXT_LINE 8
#define SHORT_CORNER 3
#define LONG_CORNER 16
#define START_LINE_1 9
#define START_LINE_2 (255 -8 -1)
#define COLUMN_1 14
#define COLUMN_2 (255 -8 -6)

#define COlOR_1 CRGB :: DarkOrange
#define COlOR_2 CRGB :: DarkBlue


// XYMatrix functions //

/**
 * Instancie les Leds et la luminosité
*/
void setup_matrix(CRGB leds_matrix[]);

/**
 * Affiche sur Score sur la Matrice 8x32
 * Indiquer :
 * - Numéro d'Equipe
 * - Score de cette équipe
 * (Peut être utiliser DrawOneFrame)
*/
void print_score(uint8_t score_1, uint8_t score_2, CRGB leds_matrix[]);

/**
 * Affiche les lettre US à partir d'une certaine case
*/
void print_US(CRGB leds_matrix[], int start_idx);

/**
 * Affiche l'animation lorsque le score change
 * (Peut être utiliser DrawOneFrame)
*/
void matrix_animation(CRGB leds_matrix[]);

/**
 * Met toutes les leds en bleu
*/
void clear_matrix(CRGB leds_matrix[]);
