#ifndef GAME_H
#define GAME_H

#include <Arduino.h>

enum GameState
{
    GAME_NOT_STARTED,
    GAME_IN_PROGRESS,
    GAME_OVER
};

enum PlayingState
{
    PLAYING,
    WAITING_FOR_PLAYER_GUESS
};

extern int *sequence;
extern int sequenceLength;
extern int currentGuessIndex;
extern GameState gameState;
extern PlayingState playingState;

void startGame();
void endGame();
void resetGame();
void printSequence();
void playSequence();
void playFromSequence(int index);
int *generateSequence();
void expandSequence();
bool checkGuess(int guess);

#endif