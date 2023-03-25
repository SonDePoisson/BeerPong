#include <FastLED.h>

#include "Beer_Pong_Strip.h"

// My Functions //

void setup_strip(CRGB leds[])
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS_STRIP);
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
    delay(1000);
    FastLED.show();
}

void strip_animation(CRGB leds[], long color_1, long color_2)
{
    for (int i = 0; i < NUM_LEDS_STRIP; i++)
    {
        if(i < NUM_LEDS_STRIP/2)
            leds[i] = color_1;
        else
            leds[i] = color_2;
        FastLED.show();
    }
}