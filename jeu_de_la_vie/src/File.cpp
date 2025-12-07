#include "../headers/File.hpp"

using namespace std;

File::File() {
    cout << "Error : No file" << endl;
}

File::File(ifstream& file) { //correction apporté 
    //passage par flux ne marche pas donc passage par référence préférable (pk à retenir)
    this->file = move(file);
}

int File::ReadHeight() {
    if(this->file.is_open()) {
        int height;
        this->file >> height;
        return height;
    }
    PrintError();
    return 0;
}

int File::ReadWidth() {
    if(this->file.is_open()) {
        int width;
        this->file >> width;
        return width;
    }
    PrintError();
    return 0;
}

vector<vector<Cell*>> File::ReadMatrix(int height, int width) {
    vector<vector<Cell*>> matrix;
    matrix.resize(height, vector<Cell*>(width, nullptr));
    if(this->file.is_open()) {
        string line;
        getline(this->file, line);
        int y = 0;
        while(getline(this->file, line) && y < height) {
            int x = 0;
            for(size_t i = 0; i < line.size() && x < width; i++) {
                if(line[i] == '1') {
                    matrix[y][x] = new AliveCell(x, y);
                    x++;
                }
                else if(line[i] == '0') {
                    matrix[y][x] = new DeadCell(x, y);
                    x++;
                }
            }
            y++;
        }
        this->file.close();
        return matrix;
    }
    PrintError();
    return matrix;
}

void File::PrintError() {
    cout << "Error : File cannot be read !" << endl;
}