#include "../headers/Grid.hpp"

using namespace std;

Grid::Grid() {
    this->height = 4;
    this->lenght = 6;
    this->matrix = {};
}

Grid::Grid(int h, int l, vector<vector<Cell*>> M) {
    this->height = h;
    this->lenght = l;
    this->matrix = M;
    this->matrix.resize(height, vector<Cell*>(lenght, nullptr));
}

Grid::~Grid() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < lenght; j++) {
            delete matrix[i][j];
        }
    }
}
int Grid::CountNeighbors(Cell* c) {
    int x = c->GetX();
    int y = c->GetY();
    int neighbors = 0;
    for(int i = max(0, y-1); i <= min(y+1, height-1); i++) {
        for(int j = max(0, x-1); j <= min(x+1, lenght-1); j++) {
            if(matrix[i][j]->GetState() && matrix[i][j] != matrix[y][x]) { 
                neighbors++;
            }
        }
    }
    return neighbors;
}

void Grid::Print() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < lenght; j++) {
            cout << matrix[i][j]->GetState() << endl;
        }
    }
}

Grid Grid::ApplyGrid() {
    vector<vector<Cell*>> matrixApply;
    matrixApply.resize(height, vector<Cell*>(lenght, nullptr));
    int y = 0;
    for(int i = 0; i < height; i++) {
        int x = 0;
        for(int j = 0; j < lenght; j++) {
            if(matrix[i][j]->GetState()) {
                if(Rules::AliveRules(this, matrix[i][j])) {
                    matrixApply[i][j] = new AliveCell(j, i);
                    matrixApply[i][j]->SetState(true);
                }
                else {
                    matrixApply[i][j] = new DeadCell(j, i);
                    matrixApply[i][j]->SetState(false);
                }
            }
            else {
                if(Rules::DeadRules(this, matrix[i][j])) {
                    matrixApply[i][j] = new AliveCell(j, i);
                    matrixApply[i][j]->SetState(true);
                }
                else {
                    matrixApply[i][j] = new DeadCell(j, i);
                    matrixApply[i][j]->SetState(false);
                }
            }
        }
    }
    Grid gridApply(this->height, this->lenght, matrixApply);
    return gridApply;
}