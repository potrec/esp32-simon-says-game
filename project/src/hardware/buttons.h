#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#define BUTTON_1 25
#define BUTTON_2 33
#define BUTTON_3 32
#define BUTTON_4 23

void initButtons();
bool readButton(int buttonPin);

#endif