#include "../headers/DeadCell.hpp"

// Constructeur
DeadCell::DeadCell(int x, int y): Cell(x, y) {
    this->state = false;
}

// Destructeur
DeadCell::~DeadCell() {}

// Renvoie l'état de la cellule : false
bool DeadCell::GetState() {
    return this->state;
}