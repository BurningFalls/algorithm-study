#include <iostream>
using namespace std;

int main() {
	int arr[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 3; i++) {
			if (arr[i % 3][j] == arr[(i + 1) % 3][j]) {
				cout << arr[(i + 2) % 3][j];
				break;
			}
		}
		cout << " ";
	}

	return 0;
}