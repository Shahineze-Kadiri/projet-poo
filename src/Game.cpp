#include "../headers/Grid.hpp"
#include "../headers/File.hpp"
#include "../headers/Display.hpp"

#include <iostream> // Pour les entrées/sorties
#include <vector> // Pour utiliser vector
#include <fstream> // Pour la gestion des fichiers
#include <string> // Pour utiliser string
#include <utility> // Pour std::move
#include <cstdlib> // Pour l'aléatoire
#include <ctime> // Pour l'initialisation aléatoire
#include <unistd.h> // Pour sleep
#include <cassert> // Pour les assertions

using namespace std; // Pour éviter d'écrire std:: partout
using namespace sf; // Pour éviter d'écrire sf:: partout

// Génère une matrice aléatoire de taille(height, width) dans un fichier txt
void generateRandomMatrix(int height, int width, const string& filename){
    ofstream out(filename);

    if(!out.is_open()) {
        cout << "Erreur : impossible d'ouvrir le fichier" << endl ;
        return;
    }
    srand(time(nullptr)); // Initialisation de l'aléatoire 
    out << height <<  " " << width << endl;
    for(int i=0; i < height ; i++){
        for(int j=0; j < width; j++){
            int value = rand()%2; // Aléatoire qui vaut soit 0 soit 1
            out << value << " ";
        }
        out << endl;
    }
    out.close();
    cout << "Matrice généré aléatoirement dans " << filename << endl;
}

// Test 1 (sans affichage) avec une matrice 5x5, dans un fichier txt
void Test1() {
    ifstream filename("matrix.txt");
    File f(move(filename)); // Déplacer le flux du fichier texte dans un objet File
    int h = f.ReadHeight(); 
    int w = f.ReadWidth(); 
    vector<vector<Cell*>> m = f.ReadMatrix(h,w); 
    Grid g(h, w, m); 
    g.UpdateGrid(); 

    assert((g.GetMatrix()[0][0]->GetState() == false) &&
    "m1[0][0] == false");
    assert((g.GetMatrix()[0][1]->GetState() == false) &&
    "m1[0][1] == false");
    assert((g.GetMatrix()[0][2]->GetState() == false) &&
    "m1[0][2] == false");
    assert((g.GetMatrix()[0][3]->GetState() == false) &&
    "m1[0][3] == false");
    assert((g.GetMatrix()[0][4]->GetState() == false) &&
    "m1[0][4] == false");
    assert((g.GetMatrix()[1][0]->GetState() == false) &&
    "m1[1][0] == false");
    assert((g.GetMatrix()[1][1]->GetState() == true) &&
    "m1[1][1] == true");
    assert((g.GetMatrix()[1][2]->GetState() == true) &&
    "m1[1][2] == true");
    assert((g.GetMatrix()[1][3]->GetState() == true) &&
    "m1[1][3] == true");
    assert((g.GetMatrix()[1][4]->GetState() == false) &&
    "m1[1][4] == false");
    assert((g.GetMatrix()[2][0]->GetState() == false) &&
    "m1[2][0] == false");
    assert((g.GetMatrix()[2][1]->GetState() == true) &&
    "m1[2][1] == true");
    assert((g.GetMatrix()[2][2]->GetState() == true) &&
    "m1[2][2] == true");
    assert((g.GetMatrix()[2][3]->GetState() == true) &&
    "m1[2][3] == true");
    assert((g.GetMatrix()[2][4]->GetState() == false) &&
    "m1[2][4] == false");
     assert((g.GetMatrix()[3][0]->GetState() == false) &&
    "m1[3][0] == false");
    assert((g.GetMatrix()[3][1]->GetState() == true) &&
    "m1[3][1] == true");
    assert((g.GetMatrix()[3][2]->GetState() == false) &&
    "m1[3][2] == false");
    assert((g.GetMatrix()[3][3]->GetState() == true) &&
    "m1[3][3] == true");
    assert((g.GetMatrix()[3][4]->GetState() == false) &&
    "m1[3][4] == false");
     assert((g.GetMatrix()[4][0]->GetState() == false) &&
    "m1[4][0] == false");
    assert((g.GetMatrix()[4][1]->GetState() == true) &&
    "m1[4][1] == true");
    assert((g.GetMatrix()[4][2]->GetState() == true) &&
    "m1[4][2] == true");
    assert((g.GetMatrix()[4][3]->GetState() == false) &&
    "m1[4][3] == false");
    assert((g.GetMatrix()[4][4]->GetState() == false) &&
    "m1[4][4] == false");

    cout << "Test completed successfully !" << endl;

    f.FileClose();
}

// Test 1 (avec affichage) avec une matrice 5x5, dans un fichier txt
void TestDisplay() { 
    int cellSize = 10;

    ifstream filename("matrix.txt");
    File f(move(filename)); // Déplacer le flux du fichier texte dans un objet File
    int h = f.ReadHeight();
    int w = f.ReadWidth();
    vector<vector<Cell*>> m = f.ReadMatrix(h,w);
    Grid g(h, w, m);

    Display display(cellSize, w, h);
    RenderWindow& window = display.GetWindow();
    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }
        display.RenderGrid(g);
        sleep(2);
        g.UpdateGrid();
    }
    f.FileClose();
}

// Test 2 (avec affichage) avec une matrice génèrer aléatoirement dans un fichier txt
void TestDisplay2() { 
    int height = 5;
    int width = 5;
    int cellSize = 2;
    cout << "Entrer la hauteur de votre matrice : " << endl;
    cin >> height;
    cout << "Entrer la largeur de votre matrice : " << endl;
    cin >> width;
    cout << "Entrer la taille des cellules : " << endl;
    cin >> cellSize;  

    generateRandomMatrix(height, width, "random_matrix.txt");

    ifstream filename("random_matrix.txt");
    File f(move(filename)); // Déplacer le flux du fichier texte dans un objet File
    int h = f.ReadHeight();
    int w = f.ReadWidth();
    vector<vector<Cell*>> m = f.ReadMatrix(h,w);
    Grid g(h, w, m);

    Display display(cellSize, w, h);
    RenderWindow& window = display.GetWindow();
    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }
        display.RenderGrid(g);
        sleep(2);
        g.UpdateGrid();
    }
    f.FileClose();
}

int main() {
    Test1();
    TestDisplay2();
    return 0;
}