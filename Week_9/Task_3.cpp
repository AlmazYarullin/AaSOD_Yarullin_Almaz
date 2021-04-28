#include "iostream"

using namespace std;


int main() {
    const int N = 4;
    const int M = 5;
    int arr[N][M];
    for (int i = 0; i < N; i++)
        arr[i][0] = 1;
    for (int i = 0; i < M; i++)
        arr[N-1][i] = 1;
    for (int i = 1; i < N-1; i++)
        for (int j = 1; j < M; j++)
            arr[i][j] = 0;
    int n, m;
    for (n = N - 2; n >= 0; n--)
        for (m = 1; m < M; m++) {
            arr[n][m] = arr[n+1][m] + arr[n][m-1];
        }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}