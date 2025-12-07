#include "../headers/Cell.hpp"

Cell::Cell(int x, int y, bool state): x(x), y(y), state(state) {}

void Cell::setState(bool state) {
    
};

int Cell:: getX() { return x };
int Cell:: getY() { return y };
