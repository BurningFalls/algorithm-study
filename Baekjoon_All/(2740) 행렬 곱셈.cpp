#include <iostream>
using namespace std;

int N, M, K;
int arr1[101][101];
int arr2[101][101];
int ans[101][101];

int func(int col, int row) {
	int sum = 0;
	for (int i = 0; i < M; i++) {
		sum += arr1[col][i] * arr2[i][row];
	}
	return sum;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			ans[i][j] = func(i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}