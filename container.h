#ifndef CONTAINER_H
#define CONTAINER_H
#define MAX_LENGTH 10000

#include <iostream>

#include "plane.h"
#include "ship.h"
#include "train.h"

class container {
public:
    int length;
    vehicle* pointer_arr[MAX_LENGTH];

    static container Initialize(int size);

    void Input(std::string input_file);

    void InputRandom();

    void RawOutput(std::string input_file);

    void CountCommonFunction();

    void SortFunction(std::string output_file);

    int BinarySearchByTime(double selected, int low, int high);
};

#endif
