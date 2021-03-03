#include "iostream"
#include "cmath"
using namespace std;

int main() {
	int x;
	int p = 0;
	cin >> x;
	for (int i = 2; pow(i, p) <= x / 2; p++);
	cout << p;
}