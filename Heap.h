#include <vector>

#ifndef WORDSEARCHA_HEAP_H
#define WORDSEARCHA_HEAP_H

using namespace std;

template <class T>
class Heap{
private:
    vector<T> vect;
    int heapSize;
public:
    Heap();
    int parent(int i);
    int left(int i);
    int right(int i);
    string getItem(int i);
    void initializeMaxHeap(vector<T> values);
    void maxHeapify(int i);
    void buildMaxHeap();
    vector<T> heapSort();
    int heapLength() { return vect.size(); }

};

#endif //WORDSEARCHA_HEAP_H

