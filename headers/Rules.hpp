#pragma once

#include "../headers/Grid.hpp"

class Rules {
    private:
        Grid* matrix;
    public:
        Rules(Grid* matrix);
        static bool AliveRules(Cell* c);
        static bool DeadRules(Cell* c);
};