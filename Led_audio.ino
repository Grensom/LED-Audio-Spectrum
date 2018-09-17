#include <FastLED.h>

#define num_leds 60
#define pin 6
#define brightness 50
#define sensitivity 5

CRGB leds[num_leds];

void setup() {
  FastLED.addLeds<WS2811, pin, GRB>(leds, num_leds);
  FastLED.setBrightness(brightness);
}

void loop() {
  int x = analogRead(0);
  x = x * sensitivity;
    if (x < 71) {
      leds[30] = CRGB(255, 0, 0);
    }
    else if (x > 71 && x <= 142) {
      leds[30] = CRGB(255, 154, 0);
    }
    else if (x > 142 && x <= 213) {
      leds[30] = CRGB(255, 255, 0);
    }
    else if (x > 213 && x <= 284) {
      leds[30] = CRGB(0, 255, 0);
    }
    else if (x > 284 && x <= 355) {
      leds[30] = CRGB(0, 0, 255);
    }
    else if (x > 355 && x <= 426) {
      leds[30] = CRGB(150, 102, 255);
    }
    else {
      leds[30] = CRGB(255, 0, 255);
    }
 
  FastLED.show();
  delay(10);
  for (int z = num_leds; z > (num_leds/2); z--) {
    leds[z] = leds[z - 1];
  }
  for (int z = 0; z < (num_leds/2); z++) {
    leds[z] = leds[z + 1];
  }
}

