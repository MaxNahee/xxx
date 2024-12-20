#include <Arduino.h>

int ledPin = 23;

void setup() {
    ledcAttachPin(ledPin, 0);
    ledcSetup(0, 5000, 8);
}

void loop() {
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(0, dutyCycle);
  }
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(0, dutyCycle);
    delay(10);
  }
}
