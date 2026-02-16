#pragma once // Inclusion multiple protection

#include "../headers/Cell.hpp"

// Classe représentant une cellule vivante
class AliveCell : public Cell {
    public:
        AliveCell(int x, int y);
        ~AliveCell();
        bool GetState() override; // Renvoie true
};