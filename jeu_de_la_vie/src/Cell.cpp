#include "cell.hpp"

Cell::Cell(int x, int y)
    : x(x), y(y), State(false) {}

void Cell::setState(bool state) {
    State = state;
}

void Cell::applyState() {
}

int Cell::getX() { return x; }
int Cell::getY() { return y; }
