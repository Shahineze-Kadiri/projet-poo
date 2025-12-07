#pragma once

#include "../headers/Cell.hpp"
#include <vector>

using namespace std;

class Grid {
    private:
        int height;
        int lenght;
        vector<Cell> matrix;
    public:
        Grid();
        Grid(int height, int lenght, vector<Cell> matrix);
        ~Grid();
        vector<Cell> GetNeighbors(Cell c);
};