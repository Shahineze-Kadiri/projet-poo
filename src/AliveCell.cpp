#include "../headers/AliveCell.hpp"

// Constructeur
AliveCell::AliveCell(int x, int y): Cell(x, y) {
    this->state = true;
}

// Destructeur
AliveCell::~AliveCell() {}

// Renvoie l'état de la cellule : true
bool AliveCell::GetState() {
    return this->state;
}
