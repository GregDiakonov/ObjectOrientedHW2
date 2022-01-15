#include "vehicle.h"

void vehicle::SimpleFunction() {
    ideal_time = way_length/speed;
}

void vehicle::Output(std::ofstream &file) {
    file<< "Speed: " << speed << "\n" << "Way Length: " << way_length << "\n"
        << "Ideal time of arrival: " << ideal_time << "\n";
}

void vehicle::RawOutput(std::ofstream& file) {
    file << speed << " " << way_length << " ";
}

double vehicle::GetIdealTime() {
    return ideal_time;
}

void vehicle::SetIdealTime(double value) {
    ideal_time = value;
}

vehicle* vehicle::InputRandom() {
    return nullptr;
}



