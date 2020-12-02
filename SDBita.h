
#ifndef SDBita_h
#define SDBita_h

#include "Arduino.h" // to resolve String

class SDBita {
    public:
      void setup(String timestamp);
      void debug(String time, float humidity, float temperature);
      void write(String time, float humidity, float temperature);
};

#endif