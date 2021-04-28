#include "iostream"

using namespace std;

int main() {
    const int n = 28;
    int arr[n] = {0, 0, 0, 0, 1, 1 ,1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 5, 5, 5, 5, 6, 9, 9, 9, 9, 9, 9};
    int x, begin, end;
    int left = 0;
    int right = n;
    cin >> x;
    int i = n / 2;
    bool flag = true;
    if (x < arr[0] || x > arr[n - 1]) 
        flag = false;
    if (flag)
        while ((arr[i] != x || arr[i-1] == x) && i != 0) {
            if (arr[i] > x && arr[i-1] < x) {
                flag = false;
                break;
            }
            if (arr[i] >= x)
                right = i;
            else 
                left = i;
            i = left + (right - left) / 2;
        }
    begin = i;
    left = 0;
    right = n;
    i = n / 2;
    if (flag)
        while ((arr[i] != x || arr[i+1] == x) && i != 0) {
            if (arr[i] <= x)
                left = i;
            else 
                right = i;
            i = left + (right - left) / 2;
        }
    end = i;
    if (flag)
        cout << begin << " " << end;
    else
    cout << "Not found";
}