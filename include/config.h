#ifndef MQTT_FUNCTIONS_H
#define MQTT_FUNCTIONS_H

#include <PubSubClient.h>

// ---------------------------------------------------------------------------
// Credenciales WiFi
// ---------------------------------------------------------------------------
const char* WIFI_SSID = "red";
const char* WIFI_PASSWORD = "12345678";

// ---------------------------------------------------------------------------
// --- MQTT ---

// ---------------------------------------------------------------------------
// Declaraciones de funciones relacionadas con MQTT
// ---------------------------------------------------------------------------
void setupMQTT(PubSubClient& client);     // Configura el cliente MQTT
void reconnectMQTT(PubSubClient& client); // Reintenta conexión si se pierde la comunicación con el broker
void publishStatus(PubSubClient& client); // Envía un mensaje JSON con el estado de los pines

#endif
