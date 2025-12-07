#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "../headers/Grid.hpp"

using namespace sf;
using namespace std;

class Display {
    private:
        const int cellSize;
        const int gridWidth;
        const int gridHeight;
        RenderWindow window;
    public:
        Display(int cellSize, int gridWidth, int gridHeight);
        ~Display();
        RenderWindow& GetWindow(); //méthode pour renvoyer les valeurs afin de créer la fenêtre 
        void RenderGrid(const vector<vector<Cell*>>& matrix); //reçoit la matrice de Grid et la modélise 
};