#include "iostream"

using namespace std;


int main() {
    int x;
    cin >> x;
    int root = x / 2;
    int left = 0;
    int right = x;
    while (root * root > x || (root+1)*(root+1) < x) {
        if (root * root > x) 
            right = root;
        else 
            left = root;
        root = left + (right - left) / 2;
    }
    cout << root;
}