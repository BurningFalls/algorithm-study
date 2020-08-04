#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[22][22];
int div_ter[22][22];
int minimum = -1;

void Divide_Territory(int x, int y, int d1, int d2) {
	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			div_ter[r][c] = 1;
		}
	}
	for (int r = 1; r <= x + d2; r++) {
		for (int c = y + 1; c <= N; c++) {
			div_ter[r][c] = 2;
		}
	}
	for (int r = x + d1; r <= N; r++) {
		for (int c = 1; c < y - d1 + d2; c++) {
			div_ter[r][c] = 3;
		}
	}
	for (int r = x + d2 + 1; r <= N; r++) {
		for (int c = y - d1 + d2; c <= N; c++) {
			div_ter[r][c] = 4;
		}
	}
}

void Decide_Five(int x, int y, int d1, int d2) {
	int r, c;
	r = x; c = y;
	while (r <= x + d1 && c >= y - d1) {
		div_ter[r][c] = 5;
		r++; c--;
	}
	r = x; c = y;
	while (r <= x + d2 && c <= y + d2) {
		div_ter[r][c] = 5;
		r++; c++;
	}
	r = x + d1; c = y - d1;
	while (r <= x + d1 + d2 && c <= y - d1 + d2) {
		div_ter[r][c] = 5;
		r++; c++;
	}
	r = x + d2; c = y + d2;
	while (r <= x + d2 + d1 && c >= y + d2 - d1) {
		div_ter[r][c] = 5;
		r++; c--;
	}

	bool flag;
	int left = 1, right = N;
	for (int i = x + 1; i < x + d1 + d2; i++) {
		for (int j = y - d1; j <= y + d2; j++) {
			if (div_ter[i][j] == 5) {
				left = j;
				break;
			}
		}
		for (int j = y + d2; j >= y - d1; j--) {
			if (div_ter[i][j] == 5) {
				right = j;
				break;
			}
		}
		for (int j = left + 1; j < right; j++) {
			div_ter[i][j] = 5;
		}
	}
}

void Calculate_minimum() {
	int sum[6] = { 0, };
	int result;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[div_ter[i][j]] += map[i][j];
		}
	}
	result = *max_element(sum + 1, sum + 6) - *min_element(sum + 1, sum + 6);
	if (minimum == -1)
		minimum = result;
	else
		minimum = min(minimum, result);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1; d1++) {
				for (int d2 = 1; d2 <= N - y; d2++) {
					if (d1 + d2 > N - x) continue;
					Divide_Territory(x, y, d1, d2);
					Decide_Five(x, y, d1, d2);
					Calculate_minimum();
				}
			}
		}
	}

	cout << minimum;

	return 0;
}