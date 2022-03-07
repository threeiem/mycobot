#ifndef EARTHSYSTEMS_H_H
#define EARTHSYSTEMS_H_H
#define SEALEVELPRESSURE_HPA (1013.25)

#include <string.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/*
EarthSystems - BME280 Object (temperature, humidity, pressure)
 */
class EarthSystems {
  private:
    Adafruit_BME280 Station;
    float Temperature;
    float Humidity;
    float Pressure;
    float Altitude;
    String Status;
    String Summary;
    bool Enabled;

  public:
    EarthSystems();
    String GetStatus();
    String GetSummary();
    float GetTemperature();
    float GetHumidity();
    float GetPressure();
    float GetAltitude();
};

#endif