#include <iostream>
using namespace std;

char arr[101][101];

int main() {
	int N;
	int K;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> K;
	if (K == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	else if (K == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][N - j - 1];
			}
			cout << "\n";
		}
	}
	else if (K == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[N - i - 1][j];
			}
			cout << "\n";
		}
	}

	return 0;
}