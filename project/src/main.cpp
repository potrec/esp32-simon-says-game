#include <Arduino.h>

#define LED_RED_PIN 13
#define PUSH_BUTTON 12
#define BUZZER 14
#define LED_YELLOW_PIN 27

int tones[] = {262, 294, 330, 349, 392, 440, 494, 523};
int currentTone = 0;
bool wasPressed = false;

void setup()
{
  Serial.begin(921600);

  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  int buttonValue = digitalRead(PUSH_BUTTON);
  if (buttonValue == LOW && !wasPressed)
  {
    tone(BUZZER, tones[currentTone]);
    digitalWrite(LED_RED_PIN, HIGH);
    wasPressed = true;
  }
  else if (buttonValue == HIGH && wasPressed)
  {
    wasPressed = false;
    digitalWrite(LED_RED_PIN, LOW);
    noTone(BUZZER);
    wasPressed = false;
    currentTone = (currentTone + 1) % 8;
  }
}