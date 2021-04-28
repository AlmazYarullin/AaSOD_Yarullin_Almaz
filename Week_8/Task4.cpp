#include "iostream"

using namespace std;


int main() {
    const int N = 4;
    const int M = 4;
    int matrix[N][M] = {{4, 6, 8, 9}, {1, 4, 5, 6}, {2, 4, 7, 10}, {3, 6, 8, 12}};
    int left = matrix[0][0];
    int right = matrix[0][M-1];
    for (int i = 0; i < N; i++) {
        left = min(left, matrix[i][0]);
        right = max(right, matrix[i][M-1]);
    }
    int med = (right - left) / 2;
    int less = 0;
    int more = 0;
    do {
        less = 0;
        more = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] > med)
                    more++;
                else if (matrix[i][j] < med)
                    less++;
            }
        if (less > more) 
            right = med;
        else if (less < more)
            left = med;
        cout << med << " " << less << " " << more << endl;
        system("pause");
        med = left + (right - left) / 2;
    }
    while (abs(less - more) > 1);
    cout << med << " " << less << " " << more;
    med = 5;
    more = 0;
    less = 0;
    for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] > med)
                    more++;
                else if (matrix[i][j] < med)
                    less++;
            }
    cout << "\nTOT  " << less << " " << more;
}