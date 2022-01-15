#include "plane.h"

vehicle* plane::InputRandom() {
    speed = (rand() % 1000)+1;
    way_length = (rand() % 10000)+1;
    capacity = (rand() % 200) + 1;
    flight_radius = (rand()%10000)+1;
    return this;
}

void plane::Output(std::ofstream& file) {
    file << "Plane\n";
    vehicle::Output(file);
    file << "Capacity: " << capacity << "\n" << "Flight Radius: " << flight_radius << "\n";
}

void plane::RawOutput(std::ofstream &file) {
    file << "Plane ";
    vehicle::RawOutput(file);
    file << capacity << " " << flight_radius << "\n";
}
