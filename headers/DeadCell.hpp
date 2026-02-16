#pragma once // Inclusion multiple protection

#include "../headers/Cell.hpp"

// Classe représentant une cellule morte
class DeadCell : public Cell {
    public:
        DeadCell(int x, int y);
        ~DeadCell();
        bool GetState() override; // Renvoie false
};