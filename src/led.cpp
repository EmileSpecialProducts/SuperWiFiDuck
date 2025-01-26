/*
   This software is licensed under the MIT License. See the license file for details.
   Source: https://github.com/spacehuhntech/WiFiDuck
 */

#include "led.h"
#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "settings.h"
namespace led
{
    Adafruit_NeoPixel strip{NEOPIXEL_NUM, -1, NEO_GRB + NEO_KHZ800};

    void begin()
    {
        strip.setPin(settings::getRGBLedPinNum());
        strip.begin();
        setColor(0, 0, 0);
    }

    void setColor(int r, int g, int b)
    {
        for (size_t i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, r, g, b);
        }
        strip.show();
    }
}
