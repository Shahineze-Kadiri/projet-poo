#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



void generateRandomMatrix(int height, int length, const string& filename){
    ofstream out(filename);

    if (!out.is_open()){
        cout<<"Erreur : impossible d'ouvrir le fichier"<<endl ;
        return;
    };

    srand(time(nullptr)); //initialisation de l'aléatoire 

    for(int i=0; i<height ; i++){
        for(int j=0; j< length; j++){
            int value = rand()%2 ; //aléatoire qui vaut soit 0 soit 1 
        };
        out <<endl;
    }
    out.close();
    cout<<"Matrice généré aléatoirement dans "<<filename<<endl;
};

int main(){
    int height = 5;
    int leigth = 5;

    generateRandomMatrix(height,leigth, "random_matrix.txt");
    return 0;

};