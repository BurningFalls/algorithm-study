#include <iostream>
#include <algorithm>
using namespace std;

int CAL(int a, int b) {
	int m = min(a, b);
	int L;
	for (int i = m; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			L = i;
			break;
		}
	}
	return a * b / L;
}

int main() {
	int arr[5];
	int ans = 0;

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				if (ans == 0) {
					ans = CAL(arr[k], CAL(arr[i], arr[j]));
				}
				else {
					ans = min(ans, CAL(arr[k], CAL(arr[i], arr[j])));
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}