#include "Grid.h"
#include <iostream>
#include <fstream>

void Grid::createGrid(string fileName) {
    ifstream inFile;
    int x, y;
    string s;
    string parameters;


    inFile.open(fileName); //open file
    //if file not found, send message and exit program
    if (inFile.fail()) {
        cerr << "Could not find file" << endl;
        exit(0);
    }
    //gets first two string to save as parameters for grid m, and n
    inFile >> x;
    inFile >> y;

    //pass variables to grid m and n private variables
    m = x;
    n = y;
    //resizes vector to specific parameters
    vect.resize(x, vector<string>(y));

        for(int i =0; i<x; i++){
            for(int j=0; j<y; j++){
                inFile >> s;
                vect[i][j] = s;
                cout << vect[i][j] << " " ;
            }
            cout << endl;
        }
    inFile.close(); //close file
}

//Grid initializer
Grid::Grid() {
    vect.empty();
}



