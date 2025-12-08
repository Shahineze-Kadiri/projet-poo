#pragma once // Inclusion multiple protection

#include "../headers/Cell.hpp"

class Grid; // Déclaration anticipée pour éviter les dépendances circulaires

using namespace std;

// Classe gérant les règles du jeu
class Rules {
    public:
        Rules();
        ~Rules();
        static bool AliveRules(Grid* matrix, Cell* c);
        static bool DeadRules(Grid* matrix, Cell* c);
};