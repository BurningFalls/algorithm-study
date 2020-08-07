#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];

int GCD(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0)
			return i;
	}
}

int main() {
	int gcd = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i == 0)
			continue;
		else if (i == 1)
			gcd = arr[1] - arr[0];
		else
			gcd = GCD(gcd, arr[i] - arr[i - 1]);
	}
	cout << (arr[N - 1] - arr[0]) / gcd + 1 - N;

	return 0;
}