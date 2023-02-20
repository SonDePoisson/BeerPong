
#define LED_PIN  3

#define COLOR_ORDER GRB
#define CHIPSET     WS2812B

#define BRIGHTNESS 64

// XYMatrix functions //

/**
 * Prend en paramètre les indices de led à allumer
 * Retourne l'indice de cette led dans le tableau C++
*/
uint16_t XY( uint8_t x, uint8_t y);

/**
 * Version safe de XY
 * (est basée sur XY)
 * 
 * Prend en paramètre les indices de led à allumer
 * Retourne l'indice de cette led dans le tableau C++
*/
uint16_t XYsafe( uint8_t x, uint8_t y);

/**
 * Permet de dessiner sur la matrice ?
*/
void DrawOneFrame( uint8_t startHue8, int8_t yHueDelta8, int8_t xHueDelta8);


// My Functions //

/**
 * Instancie les Leds et la luminosité
*/
void setup_matrix(void);

/**
 * Affiche sur Score sur la Matrice 8x32
 * Indiquer :
 * - Numéro d'Equipe
 * - Score de cette équipe
 * (Peut être utiliser DrawOneFrame)
*/
void print_score(int equipe, int score);

/**
 * Affiche l'animation lorsque le score change
 * (Peut être utiliser DrawOneFrame)
*/
void print_animation(void);
