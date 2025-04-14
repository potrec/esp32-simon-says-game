#include <Arduino.h>
#include "game.h"
#include <hardware/leds.h>
#include <hardware/buzzer.h>
#include <hardware/buttons.h>

// Sequence management constants
const int INITIAL_CAPACITY = 10;
const int CAPACITY_MULTIPLIER = 2;

// Game constants
const int MIN_RANDOM_VALUE = 0;
const int MAX_RANDOM_VALUE = 4;
const int NUM_BUTTONS = 4;

// Sound constants
const int BASE_TONE_FREQUENCY = 500;
const int TONE_FREQUENCY_INCREMENT = 100;
const int TONE_DURATION_MS = 500;

// Timing constants
const int SEQUENCE_ELEMENT_PAUSE_MS = 100;

int *sequence = nullptr;
int sequenceLength = 0;
int sequenceCapacity = 0;

bool buzzersEnabled = false;

void expandSequence()
{
    int newCapacity = sequenceCapacity == 0 ? INITIAL_CAPACITY : sequenceCapacity * CAPACITY_MULTIPLIER;

    int *newSequence = new int[newCapacity];

    for (int i = 0; i < sequenceLength; i++)
    {
        newSequence[i] = sequence[i];
    }

    if (sequence != nullptr)
    {
        delete[] sequence;
    }

    sequence = newSequence;
    sequenceCapacity = newCapacity;
}

void startGame()
{
    if (sequence != nullptr)
    {
        delete[] sequence;
        sequence = nullptr;
    }

    sequenceLength = 0;
    sequenceCapacity = 0;
}

void endGame()
{
    if (sequence != nullptr)
    {
        delete[] sequence;
        sequence = nullptr;
    }
    sequenceLength = 0;
    sequenceCapacity = 0;
}

void resetGame()
{
    sequenceLength = 0;
}

int *generateSequence()
{
    if (sequenceLength >= sequenceCapacity)
    {
        expandSequence();
    }

    int randomNumber = random(MIN_RANDOM_VALUE, MAX_RANDOM_VALUE);
    sequence[sequenceLength] = randomNumber;
    sequenceLength++;

    printSequence();

    return sequence;
}

void printSequence()
{
    Serial.print("\nCurrent sequence: ");
    for (int i = 0; i < sequenceLength; i++)
    {
        Serial.print(sequence[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void playSequence()
{
    for (int i = 0; i < sequenceLength; i++)
    {
        int ledIndex = sequence[i];
        turnLedOn(ledIndex);
        if (buzzersEnabled)
            playTone(BASE_TONE_FREQUENCY + ledIndex * TONE_FREQUENCY_INCREMENT, TONE_DURATION_MS);
        else
            delay(TONE_DURATION_MS);
        turnLedOff(ledIndex);
        delay(SEQUENCE_ELEMENT_PAUSE_MS);
    }
}