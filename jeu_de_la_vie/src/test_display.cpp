#include "../headers/Display.hpp"
#include <vector>
#include <cstdlib>  // pour rand() = aléatoire 
#include <ctime>    // pour time()

int main() {
    
    int width = 1200;   
    int height = 1200;  
    int cellSize = 10; 

    
    std::vector<std::vector<int>> matrix(height, std::vector<int>(width, 0));
    std::srand(std::time(nullptr));
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            matrix[i][j] = std::rand() % 2; // matrice aléatoire soit 0 ou 1
        }
    }

    
    Display display(cellSize, width, height);
    sf::RenderWindow& window = display.getWindow();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    
        display.renderGrid(matrix);
    }

    return 0;
}
