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
	long long int M, N, x, y;
	long long int lcm;
	bool flag;
	cin >> T;
	for (int a = 0; a < T; a++) {
		flag = false;
		cin >> M >> N >> x >> y;
		if (M < x || N < y) {
			flag = false;
		}
		else {
			lcm = (M * N) / gcd(M, N);
			for (int i = 0; M * i + x <= lcm; i++) {
				if ((M * i + x - y) % N == 0) {
					cout << M * i + x << "\n";
					flag = true;
					break;
				}
			}
		}
		if (flag == false)
			cout << "-1\n";
	}

	return 0;
}