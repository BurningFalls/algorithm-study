#include <iostream>
#include <algorithm>
using namespace std;

int func(int a, int b) {
	for (int i = min(a, b); i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
}

int main() {
	int N;
	int arr[101];
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		temp = func(arr[0], arr[i]);
		cout << arr[0] / temp << "/" << arr[i] / temp << "\n";
	}

	return 0;
}