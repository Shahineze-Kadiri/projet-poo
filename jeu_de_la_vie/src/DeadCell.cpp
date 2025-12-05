#include "DeadCell.hpp"

DeadCell::DeadCell(int x, int y)
    : Cell(x, y) {}

bool DeadCell::isAlive() const {
    return false;
}
