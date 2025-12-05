#pragma once

#include "../headers/Grid.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class File {
    private:
        ifstream file;
    public:
        File();
        File(ifstream file);
        ~File();
        void Read(const string filename);
        int ReadHeight();
        int ReadLenght();
        vector<Cell> ReadMatrix(int height, int lenght);
};
