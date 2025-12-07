#include "../headers/Display.hpp"

using namespace std;

Display::Display(int cellSize, int gridWidth, int gridHeight) :
    cellSize(cellSize),
    gridWidth(gridWidth),
    gridHeight(gridHeight),
    window(sf::VideoMode(gridWidth* cellSize, gridHeight* cellSize), "Game of Life") {}

Display::~Display() {}

sf::RenderWindow& Display::GetWindow(){
    return window;
}

void Display::RenderGrid(const vector<vector<Cell*>>& matrix){
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for(int x = 0; x < gridHeight; ++x) {
        for (int y = 0; y < gridWidth; ++y) {
            if(matrix[x][y]->GetState()) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}
