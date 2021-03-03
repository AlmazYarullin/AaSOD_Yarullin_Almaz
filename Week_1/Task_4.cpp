#include "iostream"

using namespace std;

int power(int x, unsigned p) {
	int mult = x;
	if (p == 0) {
		return 1;
	}
	while (p != 1) {
		x *= mult;
		p--;
	}
	return x;
}

int main() {
	int x, p;
	cin >> x >> p;
	cout << power(x, p);
}