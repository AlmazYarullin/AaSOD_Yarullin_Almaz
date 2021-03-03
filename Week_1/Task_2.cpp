#include "iostream"
#include "cmath"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	double a, b, c;
	cin >> a >> b >> c;
	float d = b * b - 4 * a * c;
	if (d < 0) {
		cout << "Корней нет.";
	}
	else if (d == 0) {
		cout << "x = " << (-b / 2 * a);
	}
	else {
		cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << "\nx2 = " << (-b - sqrt(d)) / (2 * a);
	}
}