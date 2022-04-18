#include "EarthSystem.hpp"

String EarthSystem::GetSummary(){
  this->Summary = this->GetTemperature();
  this->Summary += "C,\n";
  this->Summary += this->GetHumidity();
  this->Summary += "% humidity,\n";
  this->Summary += this->GetPressure();
  this->Summary += "hPa,\n"; 
  this->Summary += "Altitude: "; 
  this->Summary += this->GetAltitude(); 
  this->Summary += "meters"; 
  return this->Summary;
}

float EarthSystem::GetTemperature(){
  return this->GetTemperatureCelsius();
}

float EarthSystem::GetTemperatureCelsius(){
  return this->Station.readTemperature();
}

float EarthSystem::GetTemperatureFahrenheit(){
  return this->Station.readTemperature();
}

float EarthSystem::GetHumidity(){
  return this->Station.readHumidity();
}

float EarthSystem::GetPressure(){
  return this->Station.readPressure() / 100.0F;
}

float EarthSystem::GetAltitude(){
  return this->Station.readAltitude(SEALEVELPRESSURE_HPA);
}

bool EarthSystem::init(){
  return this->Station.begin();
}

EarthSystem::EarthSystem(){
  this->Station.begin();
}