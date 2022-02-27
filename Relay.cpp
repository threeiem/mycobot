#include "Relay.h"

Relay::Relay(int gpio, bool enable = "false", bool trigger_low = "false"){
  
  this->SetGPIO(gpio);
  this->SetTriggerLow(trigger_low);
  this->setStatus();

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
}

//------------------------------------------------------------------------------
// Get
//------------------------------------------------------------------------------

// GPIO
int Relay::GetGPIO(){
  return this->GPIO;
}

// Status
int Relay::GetStatus(){
  return digitalRead(this->GPIO); 
}

bool Relay::GetTriggerLow(){

}

//------------------------------------------------------------------------------
// Set
//------------------------------------------------------------------------------
void Relay::SetGPIO(int gpio){
  this->GPIO = gpio;
  pinMode(this->GPIO, OUTPUT);
}

void Relay::SetStatus(){
  this->Status = Relay::GetGPIO();
}

//------------------------------------------------------------------------------
// Methods
//------------------------------------------------------------------------------
Switch(){
  if (this->GetStatus() == 0) {
    digitalWrite(this->GPIO, HIGH);
  } else {
    digitalWrite(this->GPIO, LOW);
  }
  this->SetStatus();
}