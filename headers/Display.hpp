#pragma once // Inclusion multiple protection

#include <SFML/Graphics.hpp> // Pour l'affichage graphique
#include <vector> // Pour utiliser vector
#include <ctime> // Pour l'initialisation aléatoire
#include <cstdlib> // Pour l'aléatoire

#include "../headers/Grid.hpp"

using namespace sf;
using namespace std;

// Classe gérant l'affichage de la grille
class Display {
    private:
        const int cellSize;
        const int gridWidth;
        const int gridHeight;
        RenderWindow window;
    public:
        Display();
        Display(int cellSize, int gridWidth, int gridHeight);
        ~Display();
        RenderWindow& GetWindow(); //méthode pour renvoyer les valeurs afin de créer la fenêtre 
        void RenderGrid(const Grid& grid); //reçoit la matrice de Grid et la modélise 
};