#include "../headers/AliveCell.hpp"

AliveCell::AliveCell(int x, int y): Cell(x, y) {}

bool AliveCell::GetState() {
    return true;
}