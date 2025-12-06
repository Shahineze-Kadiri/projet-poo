#include "../headers/Rules.hpp"

Rules::Rules(Grid* matrix) {
    this->matrix = matrix;
}

bool Rules::AliveRules(Cell* c) {
    if(1 < matrix->CountNeighbors(c) < 4) {
        return ;
    }
    return false;
}

bool Rules::DeadRules(Cell* c) {
    if(matrix->CountNeighbors(c) == 3) {
        return true;
    }
    return false;
}