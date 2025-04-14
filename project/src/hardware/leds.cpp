#include "leds.h"

void initLeds()
{
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(LED_BLUE_PIN, OUTPUT);
    pinMode(LED_YELLOW_PIN, OUTPUT);
}

void turnLedOn(int ledIndex)
{
    switch (ledIndex)
    {
    case 0:
        digitalWrite(LED_RED_PIN, HIGH);
        break;
    case 1:
        digitalWrite(LED_GREEN_PIN, HIGH);
        break;
    case 2:
        digitalWrite(LED_BLUE_PIN, HIGH);
        break;
    case 3:
        digitalWrite(LED_YELLOW_PIN, HIGH);
        break;
    default:
        break;
    }
}

void turnLedOff(int ledIndex)
{
    switch (ledIndex)
    {
    case 0:
        digitalWrite(LED_RED_PIN, LOW);
        break;
    case 1:
        digitalWrite(LED_GREEN_PIN, LOW);
        break;
    case 2:
        digitalWrite(LED_BLUE_PIN, LOW);
        break;
    case 3:
        digitalWrite(LED_YELLOW_PIN, LOW);
        break;
    default:
        break;
    }
}