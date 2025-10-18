#include "mqtt_functions.h"
#include <WiFi.h>
#include <config.h>




void setupMQTT(PubSubClient& client) {
  client.setServer(MQTT_BROKER, MQTT_PORT);
}

void reconnectMQTT(PubSubClient& client) {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado al broker MQTT");
    } else {
      Serial.print("Fallo rc=");
      Serial.print(client.state());
      Serial.println(" — Reintentando en 5 segundos...");
      delay(5000);
    }
  }
}

void publishStatus(PubSubClient& client) {
  String payload = "{\"status\":\"OK\"}";
  client.publish(MQTT_TOPIC_STATUS, payload.c_str());
}
