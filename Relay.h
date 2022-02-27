#ifndef RELAY_H
#define RELAY_H

class Relay {
  private:
    int GPIO;
    int Status;
    bool Enabled;
    bool TriggerLow;

  public:
    Relay(int gpio, bool enable, bool trigger_low);
    int GetGPIO();
    int GetStatus();
    void SetGPIO(int gpio);
    void SetStatus();
    void Switch();
};

#endif