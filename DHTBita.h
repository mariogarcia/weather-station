/*
  DHTBita.h - .
*/
#ifndef DHTBita_h
#define DHTBita_h

#include "DHT.h"

class DHTBita {
    public:
        void setup();        
        float getTemperature();
        float getHumidity();
};

#endif