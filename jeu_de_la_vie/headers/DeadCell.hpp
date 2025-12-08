#pragma once

#include "../headers/Cell.hpp"

class DeadCell : public Cell {
    public:
        DeadCell(int x, int y);
        bool GetState() override;   // Renvoie false
};