#include "iostream"
#include "algorithm"

using namespace std;


bool func(int * a, int * b) {
    return a[1] > b[1];
}


int main() {
    int k;
    cin >> k;
    int * tt = new int [k];
    int ** tasks = new int * [k];
    for (int i = 0; i < k; i++) {
        tt[i] = -1;
        tasks[i] = new int [3];
        cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
    }
    sort(tasks, tasks + k, func);
    for (int i = 0; i < k; i++) {
        int j;
        for (j = tasks[i][2] - 1; j >= 0 && tt[j] != -1; j--) { }
        tt[j] = tasks[i][0];
    }
    cout << endl;
    for (int i = 0; i < k; i++) {
        cout << tt[i] << " ";
    }
}