/*
Grensom LED-Audio Spectrum
Only thing that needs to be adjusted is the "num_leds", "brightness", and "sensitivity" in this sketch to how many LEDs you are using
*/

#include <FastLED.h>

#define num_leds 60
#define pin 6
#define brightness 50     // can set it 0-255
#define sensitivity 5     // can set it 0-10, recommended at 5

CRGB leds[num_leds];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, pin, GRB>(leds, num_leds);
  FastLED.setBrightness(brightness);
}

void loop() {
  int x = analogRead(0);
  x = x * sensitivity;
  int y = analogRead(1);
  int d;
  //  Serial.println(y);
  int c = 0;
  if (y < 100) {
    if (x < 71) {
      leds[(num_leds/2)] = CRGB(255, 0, 0);
    }
    else if (x > 71 && x <= 142) {
      leds[(num_leds/2)] = CRGB(255, 154, 0);
    }
    else if (x > 142 && x <= 213) {
      leds[(num_leds/2)] = CRGB(255, 255, 0);
    }
    else if (x > 213 && x <= 284) {
      leds[(num_leds/2)] = CRGB(0, 255, 0);
    }
    else if (x > 284 && x <= 355) {
      leds[(num_leds/2)] = CRGB(0, 0, 255);
    }
    else if (x > 355 && x <= 426) {
      leds[(num_leds/2)] = CRGB(150, 102, 255);
    }
    else {
      leds[(num_leds/2)] = CRGB(255, 0, 255);
    }
  }
  else if (y > 100 && y <= 1000) {
    if (y >= 100 && y < 250) { //2nd up
      c = ((y - 100) * (255 / 150));
      leds[(num_leds/2)] = CRGB(255, c, 0);
    }
    else if (y >= 250 && y < 400) { //1st down
      c = ((y - 400) * (-255 / 150));
      leds[(num_leds/2)] = CRGB(c, 255, 0);
    }
    else if (y >= 400 && y < 550) { //3rd up
      c = ((y - 400) * (255 / 150));
      leds[(num_leds/2)] = CRGB(0, 255, c);
    }
    else if (y >= 550 && y < 700) {//2nd down
      c = ((y - 700) * (-255 / 150));
      leds[(num_leds/2)] = CRGB(0, c, 255);
    }
    else if (y >= 700 && y < 850) {//1st up
      c = ((y - 700) * (255 / 150));
      leds[(num_leds/2)] = CRGB(c, 0, 255);
    }
    else if (y >= 850 && y < 1000) {//3rd down
      c = ((y - 1000) * (-255 / 150));
      leds[(num_leds/2)] = CRGB(255, 0, c);
    }
    else {
      leds[(num_leds/2)] = CRGB(255, 0, 0);
    }
  }
  else {
    int a = y;
    int d;
    while (y > 1000) {
      y = analogRead(1);
      if (a >= 100 && a < 250) { //2nd up
        d = ((a - 100) * (255 / 150));
        leds[(num_leds/2)] = CRGB(255, d, 0);
      }
      else if (a >= 250 && a < 400) { //1st down
        d = ((a - 400) * (-255 / 150));
        leds[(num_leds/2)] = CRGB(d, 255, 0);
      }
      else if (a >= 400 && a < 550) { //3rd up
        d = ((a - 400) * (255 / 150));
        leds[(num_leds/2)] = CRGB(0, 255, d);
      }
      else if (a >= 550 && a < 700) {//2nd down
        d = ((a - 700) * (-255 / 150));
        leds[(num_leds/2)] = CRGB(0, d, 255);
      }
      else if (a >= 700 && a < 850) {//1st up
        d = ((a - 700) * (255 / 150));
        leds[(num_leds/2)] = CRGB(d, 0, 255);
      }
      else if (a >= 850 && a < 1000) {//3rd down
        d = ((a - 1000) * (-255 / 150));
        leds[(num_leds/2)] = CRGB(255, 0, d);
      }
      else {
        leds[(num_leds/2)] = CRGB(255, 0, 0);
      }
      FastLED.show();
      delay(60);
      fill_solid( leds, num_leds, leds[(num_leds/2)]);
      a = a + 1;
      if (a > 1023){
        a = 0;
      }
    }
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

