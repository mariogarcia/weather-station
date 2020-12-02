#include "DHTBita.h"
#include "SDBita.h"
#include "RTCBita.h"
#include "SerialBita.h"
#include "SensorPowerBita.h"

SDBita sdl;
RTCBita rtc;
DHTBita dht;
SerialBita ser;
SensorPowerBita pwd;

void setup() {
  pwd.setup();
  pwd.on(); // power up temp/rtc

  ser.setup();
  rtc.setup(); // rtc.setup(__DATE__, __TIME__);  
  dht.setup();
  sdl.setup(rtc.getTimestamp());

  pwd.off(); // power down temp/rtc
}

void loop() {
  delay(60000);
  pwd.on();

  String timestamp  = rtc.getTimestamp();  
  float humidity    = dht.getHumidity();
  float temperature = dht.getTemperature();

  sdl.write(timestamp, humidity, temperature);

  pwd.off();  
}