#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace sf ;


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
        void RenderGrid(const std::vector<std::vector<int>>& matrix); //reçoit la matrice de Grid et la modélise 
};