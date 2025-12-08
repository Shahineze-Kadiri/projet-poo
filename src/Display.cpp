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

void Display::RenderGrid(const Grid& grid){
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for(int x = 0; x < grid.GetHeight(); ++x) {
        for (int y = 0; y < grid.GetWidth(); ++y) {
            if(grid.GetMatrix()[y][x]->GetState()) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}
