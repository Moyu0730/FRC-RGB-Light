#include <FastLED.h>
#define NUM_LEDS 18

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define DATA_PIN A4
CRGB leds[NUM_LEDS];
int num = 0;

void setup() { 
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
//  for( int ind = 0 ; ind < NUM_LEDS ; ind++ ) leds[ind] = CRGB::Black;
}

void loop() { 
  for(int dot = NUM_LEDS ; dot > 0 ; dot--) {
    for( int ind = 12 ; ind < 15 ; ind++ ){
      if( dot-ind < 0 ) break;
      leds[dot-ind] = CRGB::Red;
    }
    for( int ind = 6 ; ind < 9 ; ind++ ){
      if( dot-ind < 0 ) break;
      leds[dot-ind] = CRGB::Blue;
    }
    for( int ind = 0 ; ind < 3 ; ind++ ) leds[dot-ind] = CRGB::Red;
    leds[0] = CRGB::Black;
    delay(50);
    FastLED.show();
    for( int ind = 12 ; ind < 15 ; ind++ ){
      if( dot-ind < 0 ) break;
      leds[dot-ind] = CRGB::Black;
    }
    for( int ind = 6 ; ind < 9 ; ind++ ){
      if( dot-ind < 0 ) break;
      leds[dot-ind] = CRGB::Black;
    }
    for( int ind = 0 ; ind < 3 ; ind++ ) leds[dot-ind] = CRGB::Black;
    delay(10);
  }
}
