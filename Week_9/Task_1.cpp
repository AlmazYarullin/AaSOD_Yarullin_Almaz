#include "iostream"
#include "string"
#include "ctime"

using namespace std;

void makeArray(int num, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = num % 10;
        num = num / 10;
    }
    return;
}

int size_int(int num) { 
    string strNum = to_string(num);
    return strNum.size();
}

bool rec(pair<int, bool> *parrA, int sizeA, pair<int, bool> *parrB, int sizeB, int a, int b, int numSize, int c, bool is_first) {
    if ((numSize == sizeA && is_first) || (numSize == sizeB && !is_first)) {
        if (is_first) {
            return rec(parrA, sizeA, parrB, sizeB, a, b, 0, c, false);
        }
        else {
            if (a + b == c) {
                cout << a << " + " << b << " = " << c;
                return true;
            }
            return false;
        }
    }
    pair<int, bool> *parr;
    int arrSize, num;
    if (is_first) { // 1st number
        arrSize = sizeA;
        num = a;
        parr = parrA;
    }
    else { // 2nd number
        arrSize = sizeB;
        num = b;
        parr = parrB;
    }
    for (int i = arrSize - 1; i >= 0; i--) {
        if (parr[i].second) continue;
        num = num * 10 + parr[i].first;
        numSize++;
        parr[i].second = true;
        if (is_first) {
            if (rec(parr, arrSize, parrB, sizeB, num, b, numSize, c, is_first)) {
                return true;
            }
        }
        else {
            if (rec(parrA, sizeA, parr, arrSize, a, num, numSize, c, is_first))
                return true;
        }
        parr[i].second = false;
        num = num / 10;
        numSize--;
    }
    return false;
}

int main(){
    int a, b, c, tBegin, tEnd;
    cin >> a >> b >> c;
    tBegin = clock();
    int sizeA = size_int(a);
    int sizeB = size_int(b);
    int * arrA = new int[sizeA];
    int * arrB = new int[sizeB];
    makeArray(a, arrA, sizeA);
    makeArray(b, arrB, sizeB);
    pair<int, bool> * parrA = new pair<int, bool>[sizeA];
    pair<int, bool> * parrB = new pair<int, bool>[sizeB];
    for (int i = 0; i < sizeA; i++) {
        parrA[i].first = arrA[i];
        parrA[i].second = false;
    }
    for (int i = 0; i < sizeB; i++) {
        parrB[i].first = arrB[i];
        parrB[i].second = false;
    }
    if (!rec(parrA, sizeA, parrB, sizeB, 0, 0, 0, c, true)) {
        cout << "404 Not found";
    }
    tEnd = clock();
    cout << "\ntime: " << tEnd - tBegin;
    return 0;
}