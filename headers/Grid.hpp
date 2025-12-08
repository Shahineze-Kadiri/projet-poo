#pragma once // Inclusion multiple protection

#include "../headers/Cell.hpp"
#include "../headers/AliveCell.hpp"
#include "../headers/DeadCell.hpp"
#include "../headers/Rules.hpp"
#include <vector> // Pour utiliser vector
#include <iostream> // Pour les entrées/sorties

using namespace std;

// Classe modélisant la grille de cellules
class Grid {
    private:
        int height;
        int width;
        vector<vector<Cell*>> matrix;
    public:
        Grid();
        Grid(int height, int width, vector<vector<Cell*>> matrix);
        ~Grid();
        int CountNeighbors(Cell* c);
        int GetHeight() const;
        int GetWidth() const;
        vector<vector<Cell*>> GetMatrix() const;
        void UpdateGrid();
};
