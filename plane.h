#ifndef PLANE_H
#define PLANE_H

#include "vehicle.h"

class plane: public vehicle {
protected:
    int flight_radius;
    int capacity;
public:
    plane(int s, double wl, int c, int fr) {
        speed = s;
        way_length = wl;
        capacity = c;
        flight_radius = fr;
    }

    plane() {}

    void RawOutput(std::ofstream &file);

    void Output(std::ofstream &file);

    virtual vehicle* InputRandom();
};

#endif
