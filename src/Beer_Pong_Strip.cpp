#ifdef RUN_ARDUINO
  #include <FastLED.h>
#elif RUN_TEST
  #define CRGB int
  #define uint8_t int
#endif

#include "Beer_Pong_Strip.h"

// My Functions //

void setup_strip(CRGB leds[])
{
    #ifdef RUN_ARDUINO
        FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS_STRIP);
    #endif
}

void strip_ambient(CRGB leds[], long color_1, long color_2)
{
    for (int i = 0; i < NUM_LEDS_STRIP; i++)
    {
        if(i%20 < 10)
        leds[i] = color_1;
        else
        leds[i] = color_2;   
    }
    #ifdef RUN_ARDUINO
        FastLED.show();
        delay(1000);
    #endif
}

void strip_animation(CRGB leds[], long color_1, long color_2)
{
    for (int i = 0; i < NUM_LEDS_STRIP; i++)
    {
        if(i < NUM_LEDS_STRIP/2)
            leds[i] = color_1;
        else
            leds[i] = color_2;
        #ifdef RUN_ARDUINO
        FastLED.show();
        #endif    
    }
}