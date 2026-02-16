#include "../headers/Grid.hpp"

using namespace std;

// Constructeur par défaut
Grid::Grid() {}

// Constructeur avec paramètres
Grid::Grid(int h, int w, vector<vector<Cell*>> M) {
    this->height = h;
    this->width = w;
    this->matrix = M;
    this->matrix.resize(height, vector<Cell*>(width, nullptr));
}

// Destructeur
Grid::~Grid() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            delete matrix[i][j];
        }
    }
}

// Compte le nombre de voisins vivants d'une cellule
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

// Récupère la hauteur de la grille
int Grid::GetHeight() const {
    return this->height;
}

// Récupère la largeur de la grille
int Grid::GetWidth() const {
    return this->width;
}

// Récupère la matrice de cellules
vector<vector<Cell*>> Grid::GetMatrix() const {
    return this->matrix;
}

// Met à jour la grille selon les règles du jeu
void Grid::UpdateGrid() {
    // Matrice temporaire pour stocker les nouveaux états
    vector<vector<bool>> StateMatrix;
    StateMatrix.resize(height, vector<bool>(width));

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(matrix[i][j]->GetState()) {
                if(Rules::AliveRules(this, matrix[i][j])) {
                    StateMatrix[i][j] = true; // Reste vivante
                }
                else {
                    StateMatrix[i][j] = false; // Devient morte
                }
            }
            else {
                if(Rules::DeadRules(this, matrix[i][j])) {
                    StateMatrix[i][j] = true; // Devient vivante
                }
                else {
                    StateMatrix[i][j] = false; // Reste morte
                }
            }
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j]->SetState(StateMatrix[i][j]); // Met à jour l'état de chaque cellule
        }
    }
}