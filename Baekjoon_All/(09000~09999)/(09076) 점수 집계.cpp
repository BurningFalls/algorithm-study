#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int arr[5];
	int sum;
	cin >> T;
	for (int a = 0; a < T; a++) {
		sum = 0;
		for (int i = 0; i < 5; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 5);
		if (arr[3] - arr[1] >= 4) {
			cout << "KIN\n";
		}
		else {
			for (int i = 1; i <= 3; i++) {
				sum += arr[i];
			}
			cout << sum << "\n";
		}
	}

	return 0;
}