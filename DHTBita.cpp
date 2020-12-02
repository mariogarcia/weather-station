#include "DHT.h"
#include "DHTBita.h"

#define DHTTYPE DHT11
const int DHTPin = 5;

DHT dhta(DHTPin, DHTTYPE);

void DHTBita::setup() {
    Serial.println("DHT: init!");
    dhta.begin();
}

float DHTBita::getTemperature() {
    return dhta.readTemperature();
}

float DHTBita::getHumidity() {
    return dhta.readHumidity();
}