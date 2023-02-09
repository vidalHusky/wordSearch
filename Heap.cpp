#include "Heap.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//Heap initializer
template<class T>
Heap<T>::Heap() {
    vect.empty();
}

template <class T>
int Heap<T>::parent(int i){
    return floor(i/2);
}

template <class T>
int Heap<T>::left(int i){
    return (i*2);
}

template <class T>
int Heap<T>::right(int i){
    return (i*2+1);
}

template <class T>
string Heap<T>::getItem(int i){
    if(vect.size()<i){
        cerr << "Index Out of Bounds"<<endl;
        return NULL;
    }
    return this->vect[i];
}

template <class T>
void Heap<T>::initializeMaxHeap(vector<T> values){
    vect.push_back("");
    for(const auto& i : values){
        vect.push_back(i);
    }
    vect.pop_back(); //gets rid of unwanted last "string" which is empty
}

template <class T>
void Heap<T>::maxHeapify(int i){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l <= heapSize && vect[l] > vect[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r<=heapSize && vect[r] > vect[largest]){
        largest = r;
    }
//    cout << "Vect l: "<<vect[l] << endl;
//    cout << "Vect i: "<<vect[i] << endl;
//    cout << "Vect r: "<<vect[r] << endl;
//    cout << "Vect largest: "<<vect[largest] << " largest = " << largest<< endl;
    if (largest != i){
        swap(vect[i],vect[largest]);
        maxHeapify(largest);
//        cout<<"This value is being switched " << vect[i] << " and " << vect[largest] << endl;
    }
}

template <class T>
void Heap<T>::buildMaxHeap(){
    heapSize = vect.size();
    for(int i = floor(vect.size()/2); i>=1; i--){
        maxHeapify(i);
    }
}

template <class T>
vector<T> Heap<T>::heapSort(){
    buildMaxHeap();
    for (int i = vect.size(); i>=2; i--){
        swap(vect[1],vect[i]);
        heapSize = heapSize - 1;
        maxHeapify(1);
    }
    vect.erase(vect.begin()); //gets rid of empty string that was placed at initializeMaxHeap
    return vect;
}