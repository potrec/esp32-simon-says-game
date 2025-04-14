#include <Arduino.h>
#include <hardware/leds.h>

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
    delay(500);
    turnLedOff(i);
  }
}