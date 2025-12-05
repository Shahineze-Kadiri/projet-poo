#include "../headers/File.hpp"

using namespace std;

File::File() {
    cout << "Error : No file" << endl;
}

File::File(ifstream file) {
    this->file = file;
}

void File::Read(const string filename) {
    this->file(filename);
    if(!(this->file)) {
        cout << "Error : File cannot be read" << endl;
    }
}

int File::ReadHeight() {
    this->file.Read();
    int height;
    this->file >> height;
    return height;
}

int File::ReadLenght() {
    this->file.Read();
    int lenght;
    this->file >> lenght;
    return lenght;
}

vector<Cell> File::ReadMatrix(int height, int lenght) {
    this->file.Read();
    vector<Cell> matrix;
    bool cell;
    int y = 0;
    while(getline(this->file, matrix)) {
        int i = 0;
        int x = 0;
        while(i < 2*lenght) {
            if(i%2 == 0) {
                matrix[x][y] = this->file.get(cell);
                x++;
            }
            i++;
        }
        y++;
    }
    return matrix;
}