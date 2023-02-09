#include <vector>

using namespace std;

#ifndef WORDSEARCHA_DICTIONARY_H
#define WORDSEARCHA_DICTIONARY_H

class Dictionary{
private:
    vector<string> vect;
public:
    Dictionary();
    void readDic();
    friend ostream& operator<<(ostream& ostr, const Dictionary *dic);
    void selectionSort();
    int partition(string arr[], int start, int end);
    void quickSortRecursive(string arr[], int start, int end);
    void quickSort();
    bool binarySearch(const string target);
    bool checkAlphabeticalOrder(const string lhs, const string rhs);
    void sortItWithHeapStuff();

};

#endif //WORDSEARCHA_DICTIONARY_H
