#include "../headers/Display.hpp"

Display::Display(int cellSize, int gridWidth, int gridHeight) :
    cellSize(cellSize),
    gridWidth(gridWidth),
    gridHeight(gridHeight),
    window(sf::VideoMode(gridWidth* cellSize, gridHeight* cellSize), "Game of Life") {}

Display::~Display() {}

sf::RenderWindow& Display::GetWindow(){
    return window;
}

void Display::RenderGrid(const std::vector<std::vector<int>>& matrix){
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
}
