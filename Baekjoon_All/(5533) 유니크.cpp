#include <iostream>
using namespace std;

int main() {
	int N;
	int cnt;
	cin >> N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[3];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < N; i++) {
			cnt = 0;
			for (int j = i + 1; j < N; j++) {
				if (arr[i] != 0 && arr[j] != 0 && arr[i][k] == arr[j][k]) {
					arr[j][k] = 0;
					cnt = 1;
				}
			}
			if (cnt == 1) {
				arr[i][k] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i][0] + arr[i][1] + arr[i][2] << "\n";
	}

	return 0;
}