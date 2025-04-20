#include <Arduino.h>
#include <hardware/leds.h>
#include <hardware/buzzer.h>
#include <hardware/buttons.h>
#include <game/game.h>

void setup()
{
  Serial.begin(921600);

  initLeds();
  initBuzzer();
  initButtons();
  startGame();
}

void loop()
{
  int guess = readButton();
  if (gameState == GAME_NOT_STARTED)
  {
    if (guess != -1)
    {
      startGame();
      gameState = GAME_IN_PROGRESS;
      playingState = PLAYING;
    }
    toggleLeds();
    delay(500);
    toggleLeds();
    delay(500);
  }
  else if (gameState == GAME_IN_PROGRESS)
  {
    if (playingState == PLAYING)
    {
      generateSequence();
      playSequence();
      playingState = WAITING_FOR_PLAYER_GUESS;
    }
    else if (playingState == WAITING_FOR_PLAYER_GUESS)
    {
      if (guess != -1)
      {
        if (!checkGuess(guess))
        {
          gameState = GAME_OVER;
          playingState = PLAYING;
        }
      }
    }
    delay(500);
  }
  else if (gameState == GAME_OVER)
  {
    const int LOSING_TONE_BASE = 1000;
    const int TONE_DROP = 100;
    const int TONE_DURATION = 300;
    const int PAUSE_DURATION = 50;

    toggleLeds();
    playTone(LOSING_TONE_BASE, TONE_DURATION);
    delay(PAUSE_DURATION);

    toggleLeds();
    playTone(LOSING_TONE_BASE - TONE_DROP, TONE_DURATION);
    delay(PAUSE_DURATION);

    toggleLeds();
    playTone(LOSING_TONE_BASE - (TONE_DROP * 2), TONE_DURATION);
    delay(PAUSE_DURATION);

    toggleLeds();
    playTone(LOSING_TONE_BASE - (TONE_DROP * 3), TONE_DURATION);
    delay(PAUSE_DURATION);

    toggleLeds();
    delay(500);

    endGame();
    gameState = GAME_NOT_STARTED;
  }
}