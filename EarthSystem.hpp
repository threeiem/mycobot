#ifndef EARTHSYSTEMS_HPP
#define EARTHSYSTEMS_HPP
#define SEALEVELPRESSURE_HPA (1013.25)

#include <string.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/*
EarthSystems - BME280 Object (temperature, humidity, pressure and "altitude")
 */
class EarthSystem {
  private:
    Adafruit_BME280 Station;
    float Temperature;
    String Summary;

  public:
    EarthSystem();
    Adafruit_Sensor *StationTemperatureSensor;
    Adafruit_Sensor *StationPressureSensor;
    Adafruit_Sensor *StationHumiditySensor;

    bool init();
    String GetSummary();
    float GetTemperature();
    float GetTemperatureCelsius();
    float GetTemperatureFahrenheit();
    float GetHumidity();
    float GetPressure();
    float GetAltitude();
};

#endif