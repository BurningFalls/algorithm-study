#include <iostream>
using namespace std;

int main() {
	int T;
	int K, N;
	int arr[15][15] = { 0, };

	for (int i = 1; i <= 14; i++) {
		arr[0][i] = i;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			for (int k = 1; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
		}
	}

	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> K >> N;
		cout << arr[K][N] << endl;
	}

	return 0;
}