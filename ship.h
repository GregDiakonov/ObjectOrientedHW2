#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <fstream>
#include "vehicle.h"

enum SHIP_TYPE {
    LINER=1,
    TUGBOAT=2,
    TANKER=3
};

class ship: public vehicle{
protected:
    int tonnage;
    SHIP_TYPE ship_type;
public:
    ship(int s, double wl, int t, SHIP_TYPE st) {
        speed = s;
        way_length = wl;
        tonnage = t;
        ship_type = st;
    }

    ship() {}

    virtual vehicle* InputRandom();

    virtual void RawOutput(std::ofstream &file);

    virtual void Output(std::ofstream& file);
};

#endif

