#include <iostream>
using namespace std;

int main() {
	int arr[9];
	int sum = 0;
	int a, b;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				a = i;
				b = j;
				j = 9;
				i = 9;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		cout << arr[i] << "\n";
	}


	return 0;
}