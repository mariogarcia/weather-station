#include "SensorPowerBita.h"

void SensorPowerBita::setup() {
    pinMode(7, OUTPUT);
}

void SensorPowerBita::on() {
    digitalWrite(7, HIGH);
    delay(1000);
}

void SensorPowerBita::off() {    
    delay(1000);
    digitalWrite(7, LOW);
}