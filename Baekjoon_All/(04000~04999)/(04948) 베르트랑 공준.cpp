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
	int n;
	int count;
	while (true) {
		count = 0;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = n + 1; i <= 2 * n; i++) {
			if (check(i)) {
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}