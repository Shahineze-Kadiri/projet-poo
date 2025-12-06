#include "../headers/Grid.hpp"
#include "../headers/File.hpp"

#include <iostream>
#include <fstream>
#include <utility>

using namespace std;
 
int main() {
    ifstream filename("/home/raph7/JeuDeLaVie/matrix.txt");
    File f(move(filename));
    int h = f.ReadHeight();
    int l = f.ReadLenght();
    Grid g(h, l, f.ReadMatrix(h, l));
    cout << h << endl;
    cout << l << endl;
    g.Print();
    Grid g1 = g.ApplyGrid();
    g1.Print();
    return 0;
}