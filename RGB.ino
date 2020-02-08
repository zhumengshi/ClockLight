/*************************RGB_LED*****************************/
void rgb_led(){
  // Turn the LED on, then pause
  int delaytime = 50;
  if(TIME_1){
    for(int i=0;i<4;i++){
      leds[i] = CRGB::Green;
      leds[i+3] = CRGB::Blue;
      FastLED.show();
      delay(delaytime);
      leds[i] = CRGB::Black;
      leds[i+3] = CRGB::Black;
      FastLED.show();
      delay(delaytime);
  }
  for(int i=0;i<4;i++){
      leds[i] = CRGB::Blue;
      leds[i+3] = CRGB::Green;
      FastLED.show();
      delay(delaytime);
      leds[i] = CRGB::Black;
      leds[i+3] = CRGB::Black;
      FastLED.show();
      delay(delaytime);
  }
   /* for(int i=0;i<8;i++){
      leds[i] = CRGB::Green;
      FastLED.show();
      delay(20);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(20);
  }
    for(int i=0;i<8;i++){
      leds[i] = CRGB::Blue;
      FastLED.show();
      delay(20);
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(20);
  }
      /*
      fill_solid(leds,8,CRGB::Blue);
      FastLED.show();
      delay(5000);
      fill_solid(leds,8,CRGB::Black);
      FastLED.show();
      delay(1000);
      */
  }
}
