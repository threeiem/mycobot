#include "EarthSystems.hpp"

EarthSystems::EarthSystems(){

  if (this->Station.begin()) {
    this->Status = "SUCCESS: Connected to BME280 station.";
  } else {
    this->Status = "ERROR: Unable to connect BME280";
  }
}

String EarthSystems::GetStatus(){
  return this->Status;
}

String EarthSystems::GetSummary(){
  this->Summary = (String) this->GetTemperature();
  this->Summary += "C,\n";
  this->Summary += this->GetHumidity();
  this->Summary += "% humidity,\n";
  this->Summary += this->GetPressure();
  this->Summary += "hPa,\n"; 
  return this->Summary;
}

float EarthSystems::GetTemperature(){
  this->Temperature = this->Station.readTemperature();
  return this->Temperature;
}

float EarthSystems::GetHumidity(){
  this->Humidity = this->Station.readHumidity();
  return this->Humidity;
}

float EarthSystems::GetPressure(){
  this->Pressure = this->Station.readPressure() / 100.0F;
  return this->Pressure;
}

float EarthSystems::GetAltitude(){
  return this->Altitude;
}
