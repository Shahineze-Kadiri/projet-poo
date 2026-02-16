#include "../headers/Display.hpp"

using namespace std;

// Constructeur par défaut
Display::Display() : 
    cellSize(10), 
    gridWidth(80), 
    gridHeight(80),
    // Initialise la fenêtre avec les dimensions appropriées
    window(sf::VideoMode(gridWidth* cellSize, gridHeight* cellSize), "Game of Life") {}

// Constructeur
Display::Display(int cellSize, int gridWidth, int gridHeight) :
    cellSize(cellSize),
    gridWidth(gridWidth),
    gridHeight(gridHeight),
    // Initialise la fenêtre avec les dimensions appropriées
    window(sf::VideoMode(gridWidth* cellSize, gridHeight* cellSize), "Game of Life") {}

// Destructeur
Display::~Display() {}

// Récupère la fenêtre
sf::RenderWindow& Display::GetWindow(){
    return window;
}

// Modélise la grille
void Display::RenderGrid(const Grid& grid){
    window.clear(); // Efface la fenêtre
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f)); // -1.0f pour voir les cellules séparées
    for(int x = 0; x < gridHeight; ++x) {
        for (int y = 0; y < gridWidth; ++y) {
            if(grid.GetMatrix()[y][x]->GetState()) {
                cell.setPosition(x * cellSize, y * cellSize); // Positionne la cellule
                window.draw(cell); // Dessine la cellule
            }
        }
    }
    window.display(); // Affiche la fenêtre
}
