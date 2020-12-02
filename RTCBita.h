#include "RTClib.h"

/*
  RTCBita.h - Utilities to handle time.
*/
#ifndef RTCBita_h
#define RTCBita_h

class RTCBita {
    public:
        RTC_DS3231 rtc;
        bool setup(const char*, const char*);
        bool setup();
        String getTimestamp();
};

#endif