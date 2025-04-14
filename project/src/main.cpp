#include <Arduino.h>
#include <hardware/leds.h>
#include <hardware/buzzer.h>

void setup()
{
  Serial.begin(921600);

  initLeds();
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    turnLedOn(i);
    playTone(500+i*100);
    delay(500);
    turnLedOff(i);
    stopTone();
    delay(500);
  }
}