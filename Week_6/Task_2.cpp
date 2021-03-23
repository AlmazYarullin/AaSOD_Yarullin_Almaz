#include "iostream"

using namespace std;

struct MaxHeap 
{
    int * array = new int [1];
    int size = 0;
    int maxSize = 1;

    int Parent(int i) { return (i - 1) / 2;}
    int LeftChild(int i) { return 2 * i + 1;}
    int RightChild (int i) { return 2 * i + 2;}

    void SiftUp(int i) {
        while (i > 1 && array[i] > array[Parent(i)]) {
            swap(array[i], array[Parent(i)]);
            i = Parent(i);
        }
    }

    void SiftDown(int i) { 
        int maxIndex = i;
        if (array[LeftChild(i)] > array[maxIndex] && LeftChild(i) < size) {
            maxIndex = LeftChild(i);
        }
        if (array[RightChild(i)] > array[maxIndex] && RightChild(i) < size) {
            maxIndex = RightChild(i);
        }
        if (maxIndex != i) {
            swap(array[i], array[maxIndex]);
            SiftDown(maxIndex);
        }
    }

    void Insert(int p) {
        if (size == maxSize) {
            maxSize *= 2;
            int * newArray = new int [maxSize];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            array = newArray;
        }
        array[size] = p;
            size++;
        SiftUp(size - 1);
    }

    int ExtractMax() {
        int result = array[0];
        swap(array[0], array[size - 1]);
        size--;
        SiftDown(0);
        return result;
    }

    int GetMax() {
        return array[0];
    }
};


int * HeapSort(int * array, int size) {
    MaxHeap * mxheap = new MaxHeap;
    for (int i = 0; i < size; i++) {
        mxheap->Insert(array[i]);
    }
    int * sortedArray = new int [size];
    for (int i = 0; i < size; i++) {
        sortedArray[i] = mxheap->ExtractMax();
    }
    return sortedArray;
}

int main() {
    int const size = 15;
    int array[size] = {8, 9, 15, 3, 4, 6, 11, 5, 7, 1, 100, 999, 0, 56, 77};
    int *ptr = array;
    int * sortedArray = HeapSort(ptr, size);
    for (int i = 0; i < size; i++) {
        cout << sortedArray[i] << " ";
    }
}