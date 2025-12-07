#pragma once

#include "../headers/Grid.hpp"
#include "../headers/AliveCell.hpp"
#include "../headers/DeadCell.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

class File {
    private:
        ifstream file;
    public:
        File();
        File(ifstream file);
        int ReadHeight();
        int ReadLenght();
        vector<vector<Cell*>> ReadMatrix(int height, int lenght);
        void PrintError();
};