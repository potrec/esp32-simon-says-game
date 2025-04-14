#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

#define LED_RED_PIN 13
#define LED_GREEN_PIN 12
#define LED_BLUE_PIN 14
#define LED_YELLOW_PIN 27

void initLeds();
void turnLedOn(int ledIndex);
void turnLedOff(int ledIndex);

#endif