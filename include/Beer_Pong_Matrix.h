
#define LED_PIN  2
#define NUM_LEDS_MATRIX 256

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

#define BRIGHTNESS  64  //Choose between 0 -> ??

#define MID_LINE (6*8)
#define LAST_LINE (12*8)
#define NEXT_LINE 8
#define SHORT_CORNER 3
#define LONG_CORNER 16
#define START_LINE_1 9
#define START_LINE_2 (255 -8 -1)
#define COLUMN_1 14
#define COLUMN_2 (255 -8 -6)

#ifdef RUN_ARDUINO
    #define COlOR_1 CRGB :: DarkGreen
    #define COlOR_2 CRGB :: DarkViolet
#elif RUN_TEST
    #define COlOR_1 1
    #define COlOR_2 0
#endif

#define HIGH_MATRIX 32
#define WIDTH 8

#define Xmax 32
#define nbLettre 8
#define XLettremax 2
#define YLettremax 8
#define nbLed 256


// XYMatrix functions //

void simu_matrix(CRGB leds_matrix[]);

/**
 * Instancie les Leds et la luminosité
*/
void setup_matrix(CRGB leds_matrix[]);

/**
 * Retourne la led en position XY
*/
unsigned long getLed(int x, int y);

/**
 * Affiche sur Score sur la Matrice 8x32
 * Indiquer :
 * - Numéro d'Equipe
 * - Score de cette équipe
 * (Peut être utiliser DrawOneFrame)
*/
void print_score(uint8_t score_1, uint8_t score_2, CRGB leds_matrix[]);

/*
 * Permet d'écrire (en MAJUSCULE)
*/
void print_letter(char letter, int letter_idx, CRGB leds_matrix[], long color);

/**
 * Permet d'écrire un mot
*/
void print_word(char* word, int start_pixel, CRGB leds_matrix[], long color);

/**
 * Permet de faire défiler un mot
*/
void defil_word(char word[], CRGB leds_matrix[], long color);

/**
 * 
*/
void print_US(CRGB leds_matrix[], long color);

/**
 * 
*/
void matrix_animation_serpent(CRGB leds_matrix[], long color);

/**
 * 
*/
void matrix_animation_ligne(CRGB leds_matrix[], long color_clear, long color_draw);

/**
 * Met toutes les leds en bleu
*/
void clear_matrix(CRGB leds_matrix[], long color);
