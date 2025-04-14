#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

#define BUZZER_PIN 26

void initBuzzer();
void playTone(int frequency, int duration);
void playTone(int frequency);
void stopTone();

#endif