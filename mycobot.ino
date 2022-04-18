#include "Relay.hpp"
#include "EarthSystem.hpp"
#include "Time.hpp"

// ESP32 Timing Defaults
int serial_init_delay  = 1000; // start() flywheel time in millisecond
int blink_duration = 100; // onboard LED blink time in millisecond
Time runtime = Time(1); // loop() look delay in seconds

// Power (Relay)
Relay PowerHeater(23);
Relay PowerWaterPump(19);

// Environmental Sensors
EarthSystem Environment;
bool station_startup_nominal = false;

void setup() {
  boardLEDInit();
  boardSerialInit();
  bool station_startup_nominal = Environment.init();
}

void loop() {
  boardBlink();
  Serial.println(Environment.GetTemperature());
  delay(runtime.period * 1000);
}

void boardBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blink_duration); 
  digitalWrite(LED_BUILTIN, LOW);
}

void boardBlink(int millisecond) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(millisecond); 
  digitalWrite(LED_BUILTIN, LOW);
}

void boardLEDInit() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("INFO: ESP32 onboard LED initialized");
}

void boardSerialInit() {
  Serial.begin(115200);
  delay(serial_init_delay); // Spinup time to connect to serial device in milliseconds
  Serial.println("INFO: Serial connection initialized");
} 
