#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>

class vehicle {
protected:
    int speed;
    double way_length;
    double ideal_time;
public:
    virtual vehicle* InputRandom();

    virtual void RawOutput(std::ofstream &file);

    virtual void Output(std::ofstream &file);

    void SimpleFunction();

    double GetIdealTime();

    void SetIdealTime(double value);
};

#endif
