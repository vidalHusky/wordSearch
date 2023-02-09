#include <vector>

#ifndef WORDSEARCHA_GRID_H
#define WORDSEARCHA_GRID_H

class Grid{
private:
    int m; //x size
    int n; //y size
    vector<vector<string>> vect;

public:
    Grid();
    string getLetter(int x, int y) { return vect[y][x]; }
    int getM(){return m;}
    int getN(){return n;}
    void createGrid(string fileName);
};



#endif //WORDSEARCHA_GRID_H
