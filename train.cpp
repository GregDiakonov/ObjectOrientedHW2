#include "train.h"

vehicle* train::InputRandom() {
    speed = (rand() % 1000)+1;
    way_length = (rand() % 10000)+1;
    wagon_number = (rand()%2000)+1;
    return this;
}

void train::Output(std::ofstream& file) {
    file << "Train\n";
    vehicle::Output(file);
    file << "Wagon Number: " << wagon_number << "\n";
}

void train::RawOutput(std::ofstream &file) {
    file << "Train ";
    vehicle::RawOutput(file);
    file << wagon_number << "\n";
}

