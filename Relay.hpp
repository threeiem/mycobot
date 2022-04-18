#ifndef RELAY_HPP
#define RELAY_HPP

#include <Arduino.h>

class Relay {
  private:
    int GPIO;
    int Status;
    bool Enabled;
    bool TriggerLow;

  public:
    Relay(int gpio);
    Relay(int gpio, bool enable, bool trigger_low);
    int GetGPIO();
    int GetStatus();
    bool GetTriggerLow();
    void SetGPIO(int gpio);
    void SetStatus();
    void Switch();
};

#endif