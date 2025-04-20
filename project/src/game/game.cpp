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
int currentGuessIndex = 0;
GameState gameState = GAME_NOT_STARTED;
PlayingState playingState = PLAYING;

bool buzzersEnabled = true;
bool gameStarted = false;
bool isPlayerGuessing = false;

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
    resetGame();
    gameStarted = true;
}

void endGame()
{
    if (sequence != nullptr)
    {
        delete[] sequence;
        sequence = nullptr;
    }
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        turnLedOff(i);
    }
    resetGame();
}

void resetGame()
{
    sequenceLength = 0;
    sequenceCapacity = 0;
    currentGuessIndex = 0;
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

    return sequence;
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

void playFromSequence(int index)
{
    if (index < sequenceLength)
    {
        int ledIndex = sequence[index];
        turnLedOn(ledIndex);
        if (buzzersEnabled)
            playTone(BASE_TONE_FREQUENCY + ledIndex * TONE_FREQUENCY_INCREMENT, TONE_DURATION_MS);
        else
            delay(TONE_DURATION_MS);
        turnLedOff(ledIndex);
        delay(SEQUENCE_ELEMENT_PAUSE_MS);
    }
}

bool checkGuess(int guess)
{
    if (guess == sequence[currentGuessIndex])
    {
        playFromSequence(currentGuessIndex);
        currentGuessIndex++;
        if (currentGuessIndex == sequenceLength)
        {
            currentGuessIndex = 0;
            playingState = PLAYING;
            return true;
        }
    }
    else
    {
        endGame();
        return false;
    }
    return true;
}
