#include "../headers/Rules.hpp"

Rules::Rules() {}

Rules::~Rules() {}

bool Rules::AliveRules() {
    neighbors = GetNeighbors();
    if(1 < neighbors.size() < 4) {
        return true;
    }
    return false;
}

bool Rules::DeadRules() {
    neighbors = GetNeighbors();
    if(neighbors.size() == 3) {
        return true;
    }
    return false;
}