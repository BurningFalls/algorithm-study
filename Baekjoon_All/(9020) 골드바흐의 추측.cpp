#include <iostream>
#include <math.h>
using namespace std;

bool check(int n) {
	if (n == 1) {
		return false;
	}
	else if (n == 2) {
		return true;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int T;
	int n;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> n;
		if (n == 4) {
			cout << 2 << " " << 2 << "\n";
		}
		else if ((n / 2) % 2 == 1) {
			for (int i = n / 2; i >= 3; i -= 2) {
				if (check(i) && check(n - i)) {
					cout << i << " " << n - i << "\n";
					break;
				}
			}
		}
		else {
			for (int i = n / 2 - 1; i >= 3; i -= 2) {
				if (check(i) && check(n - i)) {
					cout << i << " " << n - i << "\n";
					break;
				}
			}
		}
	}
	return 0;
}