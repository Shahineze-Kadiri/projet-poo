#include "../headers/Grid.hpp"
#include "../headers/File.hpp"
#include "../headers/Display.hpp"

#include <iostream>
#include <fstream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cassert>

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

void Test1() {
    ifstream filename("matrix.txt");
    File f(move(filename));
    int h = f.ReadHeight();
    int w = f.ReadWidth();
    vector<vector<Cell*>> m = f.ReadMatrix(h,w);
    Grid g(h, w, m);

    vector<vector<Cell*>> m1 = g.ApplyGrid();

    assert((m1[0][0]->GetState() == false) &&
    "m1[0][0] == false");
    assert((m1[0][1]->GetState() == false) &&
    "m1[0][1] == false");
    assert((m1[0][2]->GetState() == false) &&
    "m1[0][2] == false");
    assert((m1[0][3]->GetState() == false) &&
    "m1[0][3] == false");
    assert((m1[0][4]->GetState() == false) &&
    "m1[0][4] == false");
    assert((m1[1][0]->GetState() == false) &&
    "m1[1][0] == false");
    assert((m1[1][1]->GetState() == true) &&
    "m1[1][1] == true");
    assert((m1[1][2]->GetState() == true) &&
    "m1[1][2] == true");
    assert((m1[1][3]->GetState() == true) &&
    "m1[1][3] == true");
    assert((m1[1][4]->GetState() == false) &&
    "m1[1][4] == false");
    assert((m1[2][0]->GetState() == false) &&
    "m1[2][0] == false");
    assert((m1[2][1]->GetState() == true) &&
    "m1[2][1] == true");
    assert((m1[2][2]->GetState() == true) &&
    "m1[2][2] == true");
    assert((m1[2][3]->GetState() == true) &&
    "m1[2][3] == true");
    assert((m1[2][4]->GetState() == false) &&
    "m1[2][4] == false");
     assert((m1[3][0]->GetState() == false) &&
    "m1[3][0] == false");
    assert((m1[3][1]->GetState() == true) &&
    "m1[3][1] == true");
    assert((m1[3][2]->GetState() == false) &&
    "m1[3][2] == false");
    assert((m1[3][3]->GetState() == true) &&
    "m1[3][3] == true");
    assert((m1[3][4]->GetState() == false) &&
    "m1[3][4] == false");
     assert((m1[4][0]->GetState() == false) &&
    "m1[4][0] == false");
    assert((m1[4][1]->GetState() == true) &&
    "m1[4][1] == true");
    assert((m1[4][2]->GetState() == true) &&
    "m1[4][2] == true");
    assert((m1[4][3]->GetState() == false) &&
    "m1[4][3] == false");
    assert((m1[4][4]->GetState() == false) &&
    "m1[4][4] == false");

    cout << "Test completed successfully !" << endl;

    f.FileClose();
}

void TestDisplay() {
    int height = 5; 
    int width = 5;    
    int cellSize = 10;

    ifstream filename("matrix.txt");
    File f(move(filename));
    int h = f.ReadHeight();
    int w = f.ReadWidth();
    vector<vector<Cell*>> m = f.ReadMatrix(h,w);
    Grid g(h, w, m);

    Display display(cellSize, width, height);
    sf::RenderWindow& window = display.GetWindow();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        display.RenderGrid(m);
        for(int i=0; i < 10;i++) {
            sleep(3);
            m = g.ApplyGrid();
            Grid g(h, w, m);
            display.RenderGrid(m);
        }
    }
    f.FileClose();
}

void TestDisplay2() {
    int height = 1200; 
    int width = 1200;    
    int cellSize = 10;

    generateRandomMatrix(height, width, "random_matrix.txt");

    ifstream filename("random_matrix.txt");
    File f(move(filename));
    int h = f.ReadHeight();
    int w = f.ReadWidth();
    vector<vector<Cell*>> m = f.ReadMatrix(h,w);
    Grid g(h, w, m);

    Display display(cellSize, width, height);
    sf::RenderWindow& window = display.GetWindow();
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        display.RenderGrid(m);
        sleep(3);
        m = g.ApplyGrid();
        display.RenderGrid(m);
    }
    f.FileClose();
}

int main() {
    Test1();
    TestDisplay2();
    return 0;
}