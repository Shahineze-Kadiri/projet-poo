#include "../headers/Grid.hpp"
#include "../headers/File.hpp"
#include "../headers/Display.hpp"

#include <iostream>
#include <fstream>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomMatrix(int height, int width, const string& filename){
    ofstream out(filename);

    if (!out.is_open()){
        cout << "Erreur : impossible d'ouvrir le fichier" << endl ;
        return;
    };

    srand(time(nullptr)); //initialisation de l'aléatoire 

    for(int i=0; i < height ; i++){
        for(int j=0; j < width; j++){
            int value = rand()%2 ; //aléatoire qui vaut soit 0 soit 1 
        };
        out << endl;
    }
    out.close();
    cout << "Matrice généré aléatoirement dans " << filename << endl;
}

int main() {
    int height = 5; 
    int width = 5;    
    int cellSize = 10;
    vector<vector<int>> matrix(height, vector<int>(width, 0));
    generateRandomMatrix(height, width, "random_matrix.txt");
    Display display(cellSize, width, height);
    sf::RenderWindow& window = display.GetWindow();
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        display.RenderGrid(matrix);
    }
    ifstream filename("random_matrix.txt");
    File f(move(filename));
    int h = f.ReadHeight();
    int w = f.ReadWidth();
    Grid g(h, w, f.ReadMatrix(h, w));
    cout << h << endl;
    cout << w << endl;
    g.Print();
    Grid g1 = g.ApplyGrid();
    g1.Print();
    return 0;
}