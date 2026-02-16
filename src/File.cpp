#include "../headers/File.hpp"

using namespace std;

// Constructeur par défaut
File::File() {
    cout << "Error : No file" << endl;
}

// Constructeur avec paramètre
File::File(ifstream file) {
    this->file = move(file); // Déplacer le flux du fichier en paramètre dans le fichier
}

// Destructeur
File::~File() {}

// Lit la hauteur de la matrice
int File::ReadHeight() {
    if(this->file.is_open()) {
        int height;
        this->file >> height;
        return height;
    }
    cout << "Error : File cannot be read !" << endl;
    return 0;
}

// Lit la largeur de la matrice
int File::ReadWidth() {
    if(this->file.is_open()) {
        int width;
        this->file >> width;
        return width;
    }
    cout << "Error : File cannot be read !" << endl;
    return 0;
}

// Lit la matrice
vector<vector<Cell*>> File::ReadMatrix(int height, int width) {
    vector<vector<Cell*>> matrix;
    matrix.resize(height, vector<Cell*>(width, nullptr)); // Évite que la matrice dépasse les dimensions
    if(this->file.is_open()) {
        string line;
        getline(this->file, line);
        int y = 0;
        while(getline(this->file, line) && y < height) {
            int x = 0;
            for(size_t i = 0; i < line.size() && x < width; i++) {
                if(line[i] == '1') {
                    matrix[y][x] = new AliveCell(x, y); // Crée une cellule vivante
                    x++;
                }
                else if(line[i] == '0') {
                    matrix[y][x] = new DeadCell(x, y); // Crée une cellule morte
                    x++;
                }
            }
            y++;
        }
        return matrix;
    }
    cout << "Error : File cannot be read !" << endl;
    return matrix;
}

// Ferme le fichier
void File::FileClose() {
    this->file.close();
}