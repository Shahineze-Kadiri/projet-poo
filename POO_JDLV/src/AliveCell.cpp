#include "../headers/AliveCell.hpp"
#include "../headers/Cell.hpp"

AliveCell::AliveCell(int x, int y): Cell(x, y) {}

bool AliveCell::isAlive() const
{
    return true;
}
