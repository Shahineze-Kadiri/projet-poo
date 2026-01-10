#include "../headers/Rules.hpp"
#include "../headers/Grid.hpp" 

Rules::Rules() {}

bool Rules::AliveRules(Grid* matrix, Cell* c) {
    if(matrix->CountNeighbors(c) > 1 && matrix->CountNeighbors(c) < 4) {
        return true;
    }
    return false;
}

bool Rules::DeadRules(Grid* matrix, Cell* c) {
    if(matrix->CountNeighbors(c) == 3) {
        return true;
    }
    return false;
}