#include <iostream>
using namespace std;

int main() {
	int arr[2][3];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	if (arr[0][1] <= arr[1][1]) {
		if (arr[0][2] <= arr[1][2]) {
			cout << arr[1][0] - arr[0][0] << "\n";
			cout << arr[1][0] - arr[0][0] + 1 << "\n";
			cout << arr[1][0] - arr[0][0] << "\n";
		}
		else {
			cout << arr[1][0] - arr[0][0] - 1 << "\n";
			cout << arr[1][0] - arr[0][0] + 1 << "\n";
			cout << arr[1][0] - arr[0][0] << "\n";
		}
	}
	else {
		cout << arr[1][0] - arr[0][0] - 1 << "\n";
		cout << arr[1][0] - arr[0][0] + 1 << "\n";
		cout << arr[1][0] - arr[0][0] << "\n";
	}

	return 0;
}