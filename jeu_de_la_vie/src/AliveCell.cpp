#include "AliveCell.hpp"

AliveCell::AliveCell(int x, int y)
    : Cell(x, y) {}

bool AliveCell::isAlive() const {
    return true;
}
