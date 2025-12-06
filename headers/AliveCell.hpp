#pragma once

#include "../headers/Cell.hpp"

class AliveCell : public Cell {
    public:
        AliveCell(int x, int y);
        bool GetState() override;   // Renvoie true
};