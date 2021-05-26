#include "iostream"


using namespace std;


int amount(int &n, int coin) {
    int amount = 0;
    while (n >= coin) {
        n = n - coin;
        amount++;
        // cout << n << " ";
    }
    // cout << endl;
    return amount;
}


int main(){
    int n;
    cin >> n;
    cout << "10: " << amount(n, 10) << "\n5: " << amount(n, 5) << "\n1: " << amount(n, 1);
}