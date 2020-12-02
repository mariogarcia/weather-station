#include "Arduino.h" // to resolve String
#include "SDBita.h"
#include "SD.h"

File openFile() {
    return SD.open("DATA.CSV", FILE_WRITE);
}

File openInitFile() {
    return SD.open("SD_INIT.CSV", FILE_WRITE);
}

void SDBita::write(String timestamp, float humidity, float temperature) {
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("humidity or temperature not available");
        return;
    }

    File file = openFile();
  
    if (file) {
        file.print(timestamp);
        file.print(";");
        file.print(humidity);
        file.print(";");
        file.println(temperature);
        file.close();
    } else {
        Serial.println("SD: failed to write data!");
    }
}

void SDBita::debug(String timestamp, float humidity, float temperature) {
    Serial.print(timestamp);
    Serial.print(";");
    Serial.print(humidity);
    Serial.print(";");
    Serial.println(temperature);
}

void SDBita::setup(String timestamp) {
    Serial.println("SD: initializing...");
    if (!SD.begin(4)) {
        Serial.println("SD: initialization failed!");
    } else {
        // SD.begin() consumes 20mA until the SD card is read. After that
        // point consumption decreases to 1mA.
        // I'm forcing to reach the minimal consumption state ASAP
        File sdInitFile = openInitFile();     
        sdInitFile.println(timestamp);
        sdInitFile.close();
        Serial.println("SD: initialization succeeded!");
    }
    Serial.println("SD: initialization done!");
}