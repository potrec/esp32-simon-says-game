#ifndef GAME_H
#define GAME_H

#include <Arduino.h>

extern int *sequence;
extern int sequenceLength;

void startGame();
void endGame();
void resetGame();
void printSequence();
void playSequence();
int *generateSequence();
void expandSequence();

#endif