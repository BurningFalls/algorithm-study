#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0)
			return i;
	}
}

int main() {
	int T;
	int a, b;
	int gcd;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		gcd = GCD(a, b);
		cout << a * b / gcd << " " << gcd << "\n";
	}

	return 0;
}