#include <Arduino.h>

#define LED 12
#define BUTTON 9

const unsigned long strokeIntervalMs = 300;
const unsigned long blinkIntervalMs = 30;
unsigned long lastStrokeMillis = 0;
unsigned long lastBlinkMillis = 0;
bool blinking = false;

void blink(unsigned long currentMillis, bool blink) {
    if (blink) {
        if (currentMillis - lastBlinkMillis >= blinkIntervalMs) {
            digitalWrite(LED, !digitalRead(LED));
            lastBlinkMillis = currentMillis;
        }
    } else {
        digitalWrite(LED, LOW);
    }
}

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
}

void loop() {
    unsigned long currentMillis = millis();
    if (digitalRead(BUTTON) == HIGH) {
        if (currentMillis - lastStrokeMillis >= strokeIntervalMs) {
            blinking = !blinking;
            lastStrokeMillis = currentMillis;
        }
    }
    blink(currentMillis, blinking);
}