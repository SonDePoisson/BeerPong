#include <FastLED.h>

#include "Beer_Pong_Strip.h"

// My Functions //

void setup_strip(CRGB leds[])
{
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS_STRIP);
}

void strip_animation(CRGB leds[]) //TODO
{
    for (int i = 0; i < NUM_LEDS_STRIP; i++)
    {
        if(i < NUM_LEDS_STRIP/2)
            leds[i] = CRGB::Blue;
        else
            leds[i] = CRGB::Red;
        FastLED.show();
    }
}