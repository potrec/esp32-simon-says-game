#include "buttons.h"

bool buttonPreviousState[4] = {false, false, false, false};
unsigned long buttonLastPressTime[4] = {0, 0, 0, 0};
const unsigned long DEBOUNCE_TIME = 50;

void initButtons()
{
    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);
    pinMode(BUTTON_4, INPUT_PULLUP);
}

bool readButtonState(int button)
{
    bool currentState = false;

    switch (button)
    {
    case 0:
        currentState = digitalRead(BUTTON_1) == LOW;
        break;
    case 1:
        currentState = digitalRead(BUTTON_2) == LOW;
        break;
    case 2:
        currentState = digitalRead(BUTTON_3) == LOW;
        break;
    case 3:
        currentState = digitalRead(BUTTON_4) == LOW;
        break;
    default:
        return false;
    }

    if (currentState && !buttonPreviousState[button])
    {
        unsigned long currentTime = millis();
        if (currentTime - buttonLastPressTime[button] > DEBOUNCE_TIME)
        {
            buttonLastPressTime[button] = currentTime;
            buttonPreviousState[button] = true;
            return true;
        }
    }
    else if (!currentState && buttonPreviousState[button])
    {
        buttonPreviousState[button] = false;
    }

    return false;
}

int readButton()
{
    for (int i = 0; i < 4; i++)
    {
        if (readButtonState(i))
        {
            return i;
        }
    }
    return -1;
}