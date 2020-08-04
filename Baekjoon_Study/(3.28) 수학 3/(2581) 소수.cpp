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
	int M, N;
	int sum = 0;
	int min = 0;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (check(i)) {
			if (min == 0) {
				min = i;
			}
			sum += i;
		}
	}
	if (sum == 0) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
		cout << min << endl;
	}

	return 0;
}