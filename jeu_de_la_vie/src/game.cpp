#include "../headers/Grid.hpp"
#include "../headers/Rules.hpp"
#include "../headers/Display.hpp"
#include "../headers/Files.hpp"
#include <SFML/Graphics.hpp>

int main(){
    int width = 10;
    int height = 10 ;

    Grid grid(widht, height);
    grid.InitializeAleat(); //génére une grille aléatoire selon ce que l'on choisit 

    Display display(800,800, &grid);

    while (display.IsOpen()){
        display.HandleEvents();
        display.DrawGrid();
        grid.Update();
        sf::sleep(sf::miliseconds(100));
    };

    return 0 


};
