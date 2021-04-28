#include "iostream"

using namespace std;

int main() {
    const int N = 3;
    const int M = 4;
    int arr[N][M] = {{1, 3, 4, 5}, {6, 8, 10, 22}, {30, 45, 67, 68}};
    int x;
    bool flag;
    cin >> x;
    int left = 0;
    int right = N;
    int i = N / 2;
    if (x < arr[0][0] || x > arr[N-1][M-1]){
        cout << "Not found";
        return 0;
    }
    while (arr[i][0] > x || arr[i][M - 1] < x) {
        if (arr[i][0] > x)
            right = i;
        else
            left = i;
        i = left + (right - left) / 2;
    }
    cout << i;
    left = 0;
    right = M;
    int j = M / 2;
    while (right - left > 1) {
        if (arr[i][j] > x) 
            right = j;
        else
            left = j;
        j = left + (right - left) / 2;
    }
    cout << "row: " << i + 1 << "\ncolumn: " << j + 1;

}