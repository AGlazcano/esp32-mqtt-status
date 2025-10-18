#ifndef MQTT_FUNCTIONS_H
#define MQTT_FUNCTIONS_H

#include <PubSubClient.h>

// ---------------------------------------------------------------------------
// Configuración del broker MQTT
// ---------------------------------------------------------------------------

// Usa la IP directa si el DNS falla
const char* MQTT_BROKER = "85.119.83.194";
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC_STATUS = "esp32/status";

// ---------------------------------------------------------------------------
// Declaraciones de funciones relacionadas con MQTT
// ---------------------------------------------------------------------------

void setupMQTT(PubSubClient& client);
void reconnectMQTT(PubSubClient& client);
void publishStatus(PubSubClient& client);

#endif
