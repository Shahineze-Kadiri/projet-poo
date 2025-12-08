#include "../headers/Cell.hpp"

// Constructeur par défaut
Cell::Cell() {}

// Constructeur avec paramètres
Cell::Cell(int x, int y) : x(x), y(y) {
}

// Récupère la position x de la cellule
int Cell::GetX() const {
    return this->x; 
}

// Récupère la position y de la cellule
int Cell::GetY() const { 
    return this->y; 
}

// Modifie l'état de la cellule
void Cell::SetState(bool state) {
    this->state = state;
}