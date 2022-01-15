#include "ship.h"

vehicle* ship::InputRandom() {
    speed = (rand() % 1000)+1;
    way_length = (rand() % 10000)+1;
    tonnage = (rand()%2000)+1;
    int type = (rand()%3);
    if(type==0) {
        ship_type = LINER;
    }
    if(type==1) {
        ship_type = TUGBOAT;
    }
    if(type==2) {
        ship_type = TANKER;
    }
    return this;
}

void ship::RawOutput(std::ofstream &file) {
    file << "Ship ";
    vehicle::RawOutput(file);
    file << tonnage << " ";
    if(ship_type==LINER) {
        file << "1\n";
    }
    if(ship_type==TUGBOAT) {
        file << "2\n";
    }
    if(ship_type==TANKER) {
        file << "3\n";
    }
}

void ship::Output(std::ofstream& file) {
    file << "Ship\n";
    vehicle::Output(file);
    file << "Tonnage: " << tonnage << "\n";
    if(ship_type==LINER) {
        file << "Ship type: Liner\n";
    }
    if(ship_type==TUGBOAT) {
        file << "Ship type: Tugboat\n";
    }
    if(ship_type==TANKER) {
        file << "Ship type: Tanker\n";
    }
}

