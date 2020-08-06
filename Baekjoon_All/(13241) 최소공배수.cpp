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
	long long int A, B;
	long long int lcm;
	cin >> A >> B;
	lcm = A * B / gcd(A, B);
	cout << lcm;

	return 0;
}