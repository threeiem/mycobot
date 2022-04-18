#include "Relay.hpp"

// Get/Set
//------------------------------------------------------------------------------
// GPIO
int Relay::GetGPIO(){
  return this->GPIO;
}

// Status
int Relay::GetStatus(){
  int pin = this->GPIO;
  return digitalRead(pin); 
}

bool Relay::GetTriggerLow(){
  return this->TriggerLow;
}

void Relay::SetGPIO(int gpio){
  this->GPIO = gpio;
  pinMode(this->GPIO, OUTPUT);
}

void Relay::SetStatus(){
  this->Status = Relay::GetGPIO();
}

// Methods
//------------------------------------------------------------------------------
void Relay::Switch(){
  int pin = this->GetGPIO();
  if (this->GetStatus() == 0) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
  this->SetStatus();
}

// Constructor
//------------------------------------------------------------------------------
Relay::Relay(int gpio){
  this->SetGPIO(gpio);
  digitalWrite(gpio, LOW);
  
}

Relay::Relay(int gpio, bool enable = "false", bool trigger_low = "false"){

  this->SetGPIO(gpio);

  if (enable == true){
    if (trigger_low == true) {
      digitalWrite(gpio, LOW);
    } else {
      digitalWrite(gpio, HIGH);
    }
  } else {
    if (trigger_low == true) {
      digitalWrite(gpio, HIGH);
    } else {
      digitalWrite(gpio, LOW);
    }
  }

  this->SetStatus();
}