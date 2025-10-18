#ifndef PINS_H
#define PINS_H

// ---------------------------------------------------------------------------
// Definición de pines usados en el proyecto ESP32
// ---------------------------------------------------------------------------

// LEDs de salida
#define LED1 2      // LED integrado en muchas placas ESP32
#define LED2 4      // Segundo LED externo (puedes cambiar el pin si lo necesitas)

// Botones de entrada (usa resistencias internas PULLUP)
#define BTN1 12
#define BTN2 14

// Pin analógico para lectura de sensores
#define ANALOG_PIN 34   // ADC1_CH6

#endif
