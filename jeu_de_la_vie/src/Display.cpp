#include "../headers/Display.hpp"

Display:: Display(int cellSize, int gridWidth, int gridHeight) :
    cellSize(cellSize),
    gridWidth (gridWidth),
    gridHeight (gridHeight),
    window(sf::VideoMode(gridWidth* cellSize, gridHeight* cellSize), "Game of Life")
{};


sf::RenderWindow& Display:: getWindow(){
    return window;
};

void Display:: renderGrid(const std::vector<std::vector<int>>& matrix){
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            if (matrix[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
};





//fonction qui crée une matrice de 1200 par 1200, 2 paramètres (boucle) et ça initialise les cellules aléatoirement 

