#include "Relay.h"
#include "EarthSystems.hpp"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Power (Relay)
Relay Heater(23);
Relay WaterPump(19);

// Environment (I2C)
EarthSystems station;

void setup() {
  serialInit();
  builtinLEDInit();
}

void loop() {
  builtinBlink();
  Heater.Switch();
  Serial.println("----");
  Serial.println(station.GetStatus());
  Serial.println("----");
  Serial.println(station.GetSummary());
  delay(2000);
}

void builtinBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100); 
  digitalWrite(LED_BUILTIN, LOW);
}

void builtinBlink(int millisecond) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(millisecond); 
  digitalWrite(LED_BUILTIN, LOW);
}

void builtinLEDInit() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void serialInit() {
  Serial.begin(115200);
  Serial.println("\n\n\n\n\n\n\n\n\n\n");
} 