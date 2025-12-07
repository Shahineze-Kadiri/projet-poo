#include "../headers/DeadCell.hpp"

DeadCell::DeadCell(int x, int y): Cell(x, y) {}

bool DeadCell::GetState() {
    return false;
}