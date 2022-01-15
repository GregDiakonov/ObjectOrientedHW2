#ifndef TRAIN_H
#define TRAIN_H

#include "vehicle.h"

class train: public vehicle{
protected:
    int wagon_number;
public:
    train(int s, double wl, int wn) {
        speed = s;
        way_length=wl;
        wagon_number = wn;
    }

    train() {}

    virtual vehicle* InputRandom();

    virtual void RawOutput(std::ofstream &file);

    virtual void Output(std::ofstream &file);
};

#endif
