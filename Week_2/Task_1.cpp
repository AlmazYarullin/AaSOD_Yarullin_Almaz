#include "iostream"
using namespace std;


int sum(int * a, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    // Your check here
    return 0;
}