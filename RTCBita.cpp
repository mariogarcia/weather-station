#include "RTCBita.h"
#include "RTClib.h"


bool RTCBita::setup(const char *date, const char *time) {
    if (!this->setup()) {
        return false;
    }

    this->rtc.adjust(DateTime(date, time));
    return true;
}

bool RTCBita::setup() {
    if (!this->rtc.begin()) {
        Serial.println("RTC module is not available!");
        return false;
    }
    this->rtc.disable32K();
    Serial.println("RTC module is ready!");
    return true;
}

String RTCBita::getTimestamp() { 
    return this->rtc.now().timestamp();
}