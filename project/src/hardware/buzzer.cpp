#include "buzzer.h"

void setupBuzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);
}

void playTone(int frequency, int duration)
{
    tone(BUZZER_PIN, frequency, duration);
    delay(duration);
    noTone(BUZZER_PIN);
}

void playTone(int frequency)
{
    tone(BUZZER_PIN, frequency);
}

void stopTone()
{
    noTone(BUZZER_PIN);
}