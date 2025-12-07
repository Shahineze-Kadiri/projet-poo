#include "../headers/Grid.hpp"

using namespace std;

Grid::Grid() {}

Grid::Grid(int h, int w, vector<vector<Cell*>> M) {
    this->height = h;
    this->width = w;
    this->matrix = M;
    this->matrix.resize(height, vector<Cell*>(width, nullptr));
}

Grid::~Grid() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            delete matrix[i][j];
        }
    }
}
int Grid::CountNeighbors(Cell* c) {
    int x = c->GetX();
    int y = c->GetY();
    int neighbors = 0;
    for(int i = max(0, y-1); i <= min(y+1, height-1); i++) {
        for(int j = max(0, x-1); j <= min(x+1, width-1); j++) {
            if(matrix[i][j]->GetState() && matrix[i][j] != matrix[y][x]) { 
                neighbors++;
            }
        }
    }
    return neighbors;
}

void Grid::Print() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << matrix[i][j]->GetState() << endl;
        }
    }
}

vector<vector<Cell*>> Grid::ApplyGrid() {
    vector<vector<Cell*>> matrixApply;
    matrixApply.resize(height, vector<Cell*>(width, nullptr));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(matrix[i][j]->GetState()) {
                if(Rules::AliveRules(this, matrix[i][j])) {
                    matrixApply[i][j] = new AliveCell(j, i);
                }
                else {
                    matrixApply[i][j] = new DeadCell(j, i);
                }
            }
            else {
                if(Rules::DeadRules(this, matrix[i][j])) {
                    matrixApply[i][j] = new AliveCell(j, i);
                }
                else {
                    matrixApply[i][j] = new DeadCell(j, i);
                }
            }
        }
    }
    return matrixApply;
}