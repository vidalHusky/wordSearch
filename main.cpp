#include <iostream>
#include <fstream>
#include "Dictionary.cpp"
#include "Grid.cpp"

void findMatches(Grid grid1, Dictionary dic1) {
    int maxWordSize = grid1.getN(); // n
    //nested for loop to traverse each grid location as a starting point
    for (int i = 0; i < grid1.getM(); i++) {
        for (int j = 0; j < grid1.getN(); j++) {
            int xpos = i, ypos = j;
            // loop to circle all 8 directions
            for (int dir = 0; dir < 8; dir++) {
                // loop to check all words of size 2 - n
                string shword = "";
                for (int sz = 0; sz < maxWordSize; sz++) {
                    shword += grid1.getLetter(xpos, ypos);
                    if (dic1.binarySearch(shword)) { cout << shword << endl; }
                    switch (dir) {
                        case 0:
                            xpos = (xpos + 1) % maxWordSize;
                            break;
                        case 1:
                            xpos = (xpos + 1) % maxWordSize;
                            ypos = (ypos + 1) % maxWordSize;
                            break;
                        case 2:
                            ypos = (ypos + 1) % maxWordSize;
                            break;
                        case 3:
                            xpos = (xpos - 1) % maxWordSize;
                            ypos = (ypos + 1) % maxWordSize;
                            break;
                        case 4:
                            xpos = (xpos - 1) % maxWordSize;
                            break;
                        case 5:
                            xpos = (xpos - 1) % maxWordSize;
                            ypos = (ypos - 1) % maxWordSize;
                            break;
                        case 6:
                            ypos = (ypos - 1) % maxWordSize;
                            break;
                        case 7:
                            xpos = (xpos + 1) % maxWordSize;
                            ypos = (ypos - 1) % maxWordSize;
                            break;
                        default:
                            break;
                    }
                    if (xpos < 0) { xpos = maxWordSize - 1; }
                    if (ypos < 0) { ypos = maxWordSize - 1; }
                }
            }

        }
    }
}

//reads the name of the grid file from the keyboard, read the data from input files for grid and dictionary,
// and implements checking of words to print out candidate words that can be found in the dictionary.
void search(int sortingAlgorithm) {
    Dictionary *dic1 = new Dictionary();
    dic1->readDic();
    switch (sortingAlgorithm) {
        case 1:
            dic1->quickSort();
            break;
        case 2:
            dic1->selectionSort();
            break;
        case 3:
            dic1->sortItWithHeapStuff();
            break;
        default:
            dic1->quickSort();
            break;
    }
    cout << dic1 << endl;


    string fileName;
    cout << "Input grid file name:";
    cin >> fileName;


    Grid *grid1 = new Grid();
    grid1->createGrid(fileName);
    findMatches(*grid1, *dic1);

}

int main() {
    int sortAlgo;
    cout << "Choose sorting algorithm. Enter \"1\" for quick sort (default), \"2\" for selection sort, or \"3\" for heap sort:";
    cin >> sortAlgo;
    search(sortAlgo);
    Dictionary *dic1 = new Dictionary();
    return 0;
}
