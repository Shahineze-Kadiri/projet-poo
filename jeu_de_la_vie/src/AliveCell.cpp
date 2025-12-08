#include "../headers/AliveCell.hpp"

AliveCell::AliveCell(int x, int y): Cell(x, y) {
    this->state = true;
}

bool AliveCell::GetState() {
    return this->state;
}