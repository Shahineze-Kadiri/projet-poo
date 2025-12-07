#include "../headers/Cell.hpp"

Cell::Cell(int x, int y) : x(x), y(y) {}

Cell::Cell(int x, int y, bool state) : x(x), y(y), state(state) {}

void Cell::SetState(bool state) {
    this->state = state;
}

int Cell::GetX() const {
    return this->x; 
}

int Cell::GetY() const { 
    return this->y; 
}