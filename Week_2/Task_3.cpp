#include "iostream"
using namespace std;


void bubble_sort(int * a, int size) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < size - 1; i++) {
            if (a[i] > a[i+1]) {
                flag = true;
                swap(a[i], a[i+1]);
            }
        }
    }
}

int main() {
    // int a[7] = {4, 56, 14, 78, 23, 6, 5};
    // bubble_sort(a, 7);
    // for (int i = 0; i < 7; i++) {
    //     cout << a[i] << " ";
    // }
}