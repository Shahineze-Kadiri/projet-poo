#pragma once // Inclusion multiple protection

#include "../headers/Grid.hpp"
#include "../headers/AliveCell.hpp"
#include "../headers/DeadCell.hpp"
#include <vector> // Pour utiliser vector
#include <iostream> // Pour les entrées/sorties
#include <fstream> // Pour la gestion des fichiers
#include <string> // Pour utiliser string
#include <utility> // Pour std::move

using namespace std;

// Classe gérant la lecture d'un fichier contenant une matrice
class File {
    private:
        ifstream file;
    public:
        File();
        File(ifstream file);
        ~File();
        int ReadHeight();
        int ReadWidth();
        vector<vector<Cell*>> ReadMatrix(int height, int width);
        void FileClose();
};
