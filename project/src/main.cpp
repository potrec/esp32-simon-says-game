#include <Arduino.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("Hello, world!");
}

void loop()
{
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Hello, world!2");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}
