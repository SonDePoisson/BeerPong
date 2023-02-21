
#define LED_PIN  3
#define NUM_LEDS_MATRIX 256

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

#define BRIGHTNESS 64

#define MID_LINE (7*8)
#define LAST_LINE (14*8)
#define NEXT_LINE 8
#define START_LINE_2 (255 -8 -1)
#define COLUMN_2 (255 -8 -1 -6)


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
 * Affiche l'animation lorsque le score change
 * (Peut être utiliser DrawOneFrame)
*/
void print_animation(CRGB leds_matrix[]);
