// How many leds in your strip?
#define NUM_LEDS_STRIP 30

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3

/**
 * Instancie les leds (strip)
*/
void setup_strip(CRGB leds[]);


/**
 * Réalise une animation
*/
void strip_animation(CRGB leds[]);