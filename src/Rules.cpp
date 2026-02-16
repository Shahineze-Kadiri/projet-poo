#include "../headers/Rules.hpp"
#include "../headers/Grid.hpp"  // Inclusion de Grid pour utiliser CountNeighbors

// Constructeur par défaut
Rules::Rules() {}

// Destructeur
Rules::~Rules() {}

// Règles pour une cellule vivante
bool Rules::AliveRules(Grid* matrix, Cell* c) {
    // Une cellule vivante avec 2 ou 3 voisins vivants survit
    if(matrix->CountNeighbors(c) > 1 && matrix->CountNeighbors(c) < 4) {
        return true;
    }
    return false;
}

// Règles pour une cellule morte
bool Rules::DeadRules(Grid* matrix, Cell* c) {
    // Une cellule morte avec exactement 3 voisins vivants devient vivante
    if(matrix->CountNeighbors(c) == 3) {
        return true;
    }
    return false;
}