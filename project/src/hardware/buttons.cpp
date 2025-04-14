#include "buttons.h"

void initButtons()
{
    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);
    pinMode(BUTTON_4, INPUT_PULLUP);
}

bool readButton(int button)
{
    switch (button)
    {
    case 0:
        return digitalRead(BUTTON_1) == LOW;
    case 1:
        return digitalRead(BUTTON_2) == LOW;
    case 2:
        return digitalRead(BUTTON_3) == LOW;
    case 3:
        return digitalRead(BUTTON_4) == LOW;
    default:
        return false;
    }
}