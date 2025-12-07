#include "../headers/DeadCell.hpp"
#include "../headers/Cell.hpp"

DeadCell::DeadCell(int x, int y): DeadCell(x, y) {}

bool DeadCell::isAlive() {
    return false;
}
