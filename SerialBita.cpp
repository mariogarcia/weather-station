#include "Arduino.h"
#include "SerialBita.h"

void SerialBita::setup() {
    Serial.begin(9600);
    while(!Serial) {
        // wait until serial is available
    }
    Serial.println("Serial is available!");
}