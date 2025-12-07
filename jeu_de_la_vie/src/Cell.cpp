#include "../headers/Cell.hpp"

Cell::Cell(int x, int y) : x(x), y(y) {};

int Cell::GetX() const {
    return this->x; 
}

int Cell::GetY() const { 
    return this->y; 
}