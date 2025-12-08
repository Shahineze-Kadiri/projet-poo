#include "../headers/DeadCell.hpp"

DeadCell::DeadCell(int x, int y): Cell(x, y) {
    this->state = false;
}

bool DeadCell::GetState() {
    return this->state;
}