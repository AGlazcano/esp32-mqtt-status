#include "mqtt_functions.h"
#include "config.h"
#include "pins.h"
#include <ArduinoJson.h>

// Variables globales
WiFiClientSecure espClient;
PubSubClient client(espClient);

// ------------------ WiFi ------------------
void setup_wifi() {
  Serial.print("\nConectando a WiFi: ");
  Serial.println(WIFI_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 60) {
      Serial.println("\n❌ Error: No se pudo conectar al WiFi");
      return;
    }
  }

  Serial.println("\n✅ WiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

// ------------------ MQTT ------------------
void mqtt_connect() {
  espClient.setInsecure();  // Solo para pruebas, desactiva verificación TLS
  client.setServer(MQTT_SERVER, MQTT_PORT);

  Serial.print("Conectando al broker MQTT...");

  while (!client.connected()) {
    if (client.connect("ESP32Client", MQTT_USER, MQTT_PASS)) {
      Serial.println("✅ Conectado al broker MQTT");
    } else {
      Serial.print("❌ Falla MQTT rc=");
      Serial.print(client.state());
      Serial.println(" (reintentando en 2s)");
      delay(2000);
    }
  }
}

// Mantiene la conexión activa
void mqtt_loop() {
  if (!client.connected()) {
    mqtt_connect();
  }
  client.loop();
}

// ------------------ JSON Publish ------------------
void mqtt_publish_json(int led1, int led2, int btn1, int btn2, int analogValue) {
  StaticJsonDocument<256> doc;

  doc["led1"] = led1;
  doc["led2"] = led2;
  doc["btn1"] = btn1;
  doc["btn2"] = btn2;
  doc["analog"] = analogValue;

  char buffer[256];
  size_t len = serializeJson(doc, buffer);

  bool ok = client.publish(MQTT_TOPIC, buffer, len);
  Serial.print("📤 Enviado a MQTT: ");
  Serial.println(buffer);
  Serial.print("Estado publicación: ");
  Serial.println(ok ? "✔️ OK" : "❌ FALLÓ");
}
