#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0)
			return i;
	}
}

int main() {
	int x1, x2;
	int y1, y2;
	int Up, Down;
	int Gcd;
	cin >> x1 >> x2;
	cin >> y1 >> y2;
	Down = x2 * y2 / gcd(x2, y2);
	Up = x1 * (Down / x2) + y1 * (Down / y2);
	Gcd = gcd(Down, Up);
	cout << Up / Gcd << " " << Down / Gcd;

	return 0;
}