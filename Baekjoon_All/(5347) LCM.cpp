#include <iostream>
#include <algorithm>
using namespace std;

long long int gcd(long long int a, long long int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0)
			return i;
	}
}

int main() {
	int N;
	long long int a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << "\n";
	}

	return 0;
}