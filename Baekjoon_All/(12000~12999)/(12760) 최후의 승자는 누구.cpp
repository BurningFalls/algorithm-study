#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N, M;
	int arr[101][101];
	int score[101] = { 0, };
	int maximum;
	int maximum_score = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
		sort(arr[i], arr[i] + M, compare);
	}

	for (int i = 0; i < M; i++) {
		maximum = 0;
		for (int j = 0; j < N; j++) {
			if (maximum < arr[j][i]) {
				maximum = arr[j][i];
			}
		}
		for (int j = 0; j < N; j++) {
			if (maximum == arr[j][i])
				score[j + 1]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (maximum_score < score[i]) {
			maximum_score = score[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (maximum_score == score[i])
			cout << i << " ";
	}

	return 0;
}