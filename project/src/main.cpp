#include <Arduino.h>
#include <hardware/leds.h>
#include <hardware/buzzer.h>
#include <hardware/buttons.h>

void setup()
{
  Serial.begin(921600);

  initLeds();
  initBuzzer();
  initButtons();
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    if (readButton(i))
    {
      Serial.printf("Button %d pressed\n", i);
      turnLedOn(i);
      playTone(500 + i * 100, 500);
    }
    delay(500);
    turnLedOff(i);
  }
}