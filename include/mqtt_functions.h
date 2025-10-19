#ifndef MQTT_FUNCTIONS_H
#define MQTT_FUNCTIONS_H

#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// Externs → definidos en mqtt_functions.cpp
extern WiFiClientSecure espClient;
extern PubSubClient client;

// Funciones
void setup_wifi();
void mqtt_connect();
void mqtt_loop();
void mqtt_publish_json(int led1, int led2, int btn1, int btn2, int analogValue);

#endif
