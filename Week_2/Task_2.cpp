#include "iostream"
using namespace std;


int main() {
    int first_array_size = 5;
    int second_array_size = 8;
    int * first_array = new int[first_array_size];
    int * second_array = new int[second_array_size];
    for (int i = 0; i < first_array_size; i++) {
        first_array[i] = 1;
    }
    for (int i = 0; i < second_array_size; i++) {
        second_array[i] = 2;
    }
    int * third_array = new int[first_array_size + second_array_size];
    for (int i = 0; i < first_array_size; i++) {
        third_array[i] = first_array[i];
    }
    for (int i = 0; i < second_array_size; i++) {
        third_array[i + first_array_size] = second_array[i];
    }
    delete[] first_array;
    delete[] second_array;
    return 0;
}