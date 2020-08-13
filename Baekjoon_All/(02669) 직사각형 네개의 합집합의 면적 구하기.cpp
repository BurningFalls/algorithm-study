#include <iostream>
using namespace std;

int main() {
	int arr[4][4];
	bool map[101][101] = { 0, };
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < 4; k++) {
		for (int i = arr[k][1]; i < arr[k][3]; i++) {
			for (int j = arr[k][0]; j < arr[k][2]; j++) {
				map[i][j] = 1;
			}
		}
	}


	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";

	return 0;
}