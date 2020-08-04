#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int arr[129][129];
int blue_cnt = 0;
int white_cnt = 0;

void compressing(int n, int y, int x) {
	int zero_cnt = 0;
	int one_cnt = 0;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] == 0)
				zero_cnt++;
			else if (arr[i][j] == 1)
				one_cnt++;
		}
	}
	if (zero_cnt == n * n) {
		white_cnt++;
		return;
	}
	else if (one_cnt == n * n) {
		blue_cnt++;
		return;
	}

	compressing(n / 2, y, x);
	compressing(n / 2, y, x + n / 2);
	compressing(n / 2, y + n / 2, x);
	compressing(n / 2, y + n / 2, x + n / 2);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	compressing(N, 0, 0);

	cout << white_cnt << "\n" << blue_cnt;

	return 0;
}
