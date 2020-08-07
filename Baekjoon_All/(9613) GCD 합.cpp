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
	int n;
	int arr[101];
	long long int sum = 0;
	cin >> T;
	for (int a = 0; a < T; a++) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << "\n";
	}

	return 0;
}