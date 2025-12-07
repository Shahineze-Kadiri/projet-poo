#include "../headers/Grid.hpp"
#include "../headers/File.hpp"
#include "../headers/Display.hpp"

#include <iostream>
#include <fstream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;
using namespace sf;

void generateRandomMatrix(int height, int width, const string& filename){
    ofstream out(filename);

    if(!out.is_open()){
        cout << "Erreur : impossible d'ouvrir le fichier" << endl ;
        return;
    }
    srand(time(nullptr)); //initialisation de l'aléatoire 
    out << height <<  " " << width << endl;
    for(int i=0; i < height ; i++){
        for(int j=0; j < width; j++){
            int value = rand()%2; //aléatoire qui vaut soit 0 soit 1
            out << value << " ";
        }
        out << endl;
    }
    out.close();
    cout << "Matrice généré aléatoirement dans " << filename << endl;
}

int main() {
    int height = 5; 
    int width = 5;    
    int cellSize = 10;
    generateRandomMatrix(height, width, "random_matrix.txt");
    ifstream filename("random_matrix.txt");
    File f(move(filename));
    int h = f.ReadHeight();
    int w = f.ReadWidth();
    vector<vector<Cell*>> m = f.ReadMatrix(h,w);
    Grid g(h, w, m);
    vector<vector<Cell*>> m1 = g.ApplyGrid();
    
    Display display(cellSize, width, height);
    sf::RenderWindow& window = display.GetWindow();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        display.RenderGrid(m);
        window.display();
        sleep(1);
        display.RenderGrid(m1);
    }
    f.FileClose();
    return 0;
}