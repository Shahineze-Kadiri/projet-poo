#pragma once

#include "../headers/Cell.hpp"

class Grid;

using namespace std;

class Rules {
    public:
        Rules();
        static bool AliveRules(Grid* matrix, Cell* c);
        static bool DeadRules(Grid* matrix, Cell* c);
};