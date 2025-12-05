#include "DeadCell.hpp"

DeadCell::DeadCell(int x, int y): DeadCell(x, y) {}

bool DeadCell::isAlive() {
    return false;
}
