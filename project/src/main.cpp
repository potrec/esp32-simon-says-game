#include <Arduino.h>
#include <hardware/leds.h>
#include <hardware/buzzer.h>
#include <hardware/buttons.h>
#include <game/game.h>

void setup()
{
  Serial.begin(921600);

  initLeds();
  initBuzzer();
  initButtons();
  startGame();
}

void loop()
{
  generateSequence();
  playSequence();
  delay(1000);
}