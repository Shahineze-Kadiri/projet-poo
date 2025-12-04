#include "../headers/Grid.hpp"

Grid::Grid() {
    this->height = 4;
    this->lenght = 6;
    this->matrix = M {4,6};
}

Grid::Grid(int h, int l, vector<Cell> M) {
    this->height = h;
    this->lenght = l;
    this->matrix = M;
}

Grid::~Grid() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < lenght; j++) {
            delete.matrix[i][j];
        }
    }
}

vector<Cell> Grid::GetNeighbors(Cell c) {
    int x = c.GetX();
    int y = c.GetY();
    vector<Cell> Neighbors;
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            if(matrix[i][j].IsAlive() && matrix[i][j] != matrix[x][y]) { 
                Neighbors.push_back(matrix[i][j]);
            }
        }
    }
    return Neighbors;
}