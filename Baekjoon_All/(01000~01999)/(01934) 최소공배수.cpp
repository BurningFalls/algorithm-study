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
	int T;
	int A, B;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> A >> B;
		cout << A * B / gcd(A, B) << "\n";
	}

	return 0;
}