#include <Arduino.h>
#include "pins.h"
#include "mqtt_functions.h"

unsigned long lastMsg = 0;
const unsigned long interval = 5000; // ms

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  setup_wifi();
  mqtt_connect();
}

void loop() {
  mqtt_loop();

  unsigned long now = millis();
  if (now - lastMsg >= interval) {
    lastMsg = now;

    int estadoLED1 = digitalRead(LED1);
    int estadoLED2 = digitalRead(LED2);
    int estadoBTN1 = digitalRead(BTN1);
    int estadoBTN2 = digitalRead(BTN2);
    int analogValue = analogRead(ANALOG_PIN);

    mqtt_publish_json(estadoLED1, estadoLED2, estadoBTN1, estadoBTN2, analogValue);
  }
}
