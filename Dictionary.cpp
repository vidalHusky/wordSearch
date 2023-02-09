#include <iostream>
#include <fstream>

#include "Heap.cpp"
#include "Dictionary.h"

//Dictionary initializer
Dictionary::Dictionary() {
    vect.empty();
}

//reads dictionary to vector
void Dictionary::readDic() {
    ifstream inFile;

    inFile.open("Dictionary.txt"); //open file
    if (inFile.fail()) {
        cerr << "Could not find file" << endl;
        exit(0);
    }
    while (!inFile.eof()) // Step 3: Read with a loop.
    {
        string s;
        getline(inFile, s); // To read an entire line at once.
        vect.push_back(s);
    }
    inFile.close(); //close file

}

//Sort dictionary alphabetically

void Dictionary::selectionSort() {
    int min_index;
    for (int i = 0; i < vect.size() - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < vect.size(); j++) {
            //checks to see if the string at vect[j] has higher alphabetical precedance than vector[min_index]
            if (checkAlphabeticalOrder(vect[j], vect[min_index])) {
                min_index = j;
            }
        }
        swap(vect[min_index], vect[i]);
    }
}

void Dictionary::quickSort() {
    string *a = &vect[0];
    quickSortRecursive(a, 0, this->vect.size() - 1);
}

// left --> starting index right --> high index
void Dictionary::quickSortRecursive(string arr[], int left, int right) {
    if (left >= right)
        return;

    // find pivot
    int p = partition(arr, left, right);

    // sort left part
    quickSortRecursive(arr, left, p - 1);

    // sort right part
    quickSortRecursive(arr, p + 1, right);
}


int Dictionary::partition(string arr[], int left, int right) {
    int count = 0;
    string pivot = arr[left];

    for (int i = left + 1; i <= right; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = left + count;
    swap(arr[pivotIndex], arr[left]);

    while (left < pivotIndex && right > pivotIndex) {

        while (arr[left] <= pivot) {
            left++;
        }

        while (arr[right] > pivot) {
            right--;
        }

        if (left < pivotIndex && right > pivotIndex) {
            swap(arr[left++], arr[right--]);
        }
    }
    return pivotIndex;
}

//void Dictionary::quickSort(){
//
//}


//returns true if rhs is more alphabetical than lhs, returns false if other way around
bool Dictionary::checkAlphabeticalOrder(const string rhs, const string lhs) { // rhs = j, lhs = min_index
    int i = 0;
    int j = 0;
    while (i < rhs.size() || j < lhs.size()) {
        //a<b : rhs is closer to index 0 on alphabet list than lhs
        if (rhs[i] < lhs[j]) {
            return true;

        } else if (lhs[j] < rhs[i]) {
            return false;

        }
        i++;
        j++;
    }
    return false;
}

//searches dictionary for specific target
bool Dictionary::binarySearch(const string target) {
    int first = 0;
    int last = vect.size() - 1;
    int mid;
    string midValue;


    while (first <= last) {
        mid = (first + last) / 2;
        midValue = vect[mid];
        if (target == midValue) {
            return true;
        } else if (!checkAlphabeticalOrder(midValue, target)) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return false;
}

//Prints out all index of vector using overloaded ostream
ostream &operator<<(ostream &ostr, const Dictionary *dic) {
    string s;
    for (const auto &i: dic->vect) {
        ostr << i << endl;
    }
    return ostr;
}

void Dictionary::sortItWithHeapStuff(){
    Heap<string>*heapers = new Heap<string>;
    heapers->initializeMaxHeap(vect);
    vect = heapers->heapSort();

}
