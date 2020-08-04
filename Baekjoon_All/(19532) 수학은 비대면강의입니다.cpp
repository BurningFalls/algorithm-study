#include <iostream>
using namespace std;

int main() {
	int arr[6];
	for (int i = 0; i < 6; i++)
		cin >> arr[i];
	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if (arr[0] * i + arr[1] * j == arr[2] && arr[3] * i + arr[4] * j == arr[5]) {
				cout << i << " " << j;
				break;
			}
		}
	}

	return 0;
}