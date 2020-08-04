#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
char arr[65][65];

void compressing(int n, int y, int x) {
	if (n == 1) {
		cout << arr[y][x];
		return;
	}
	else {
		int zero_count = 0;
		int one_count = 0;
		for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {
				if (arr[i][j] == '0')
					zero_count++;
				else if (arr[i][j] == '1')
					one_count++;
			}
		}
		if (zero_count == n * n) {
			cout << "0";
			return;
		}
		else if (one_count == n * n) {
			cout << "1";
			return;
		}
	}
	cout << "(";
	compressing(n / 2, y, x);
	compressing(n / 2, y, x + n / 2);
	compressing(n / 2, y + n / 2, x);
	compressing(n / 2, y + n / 2, x + n / 2);
	cout << ")";
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	compressing(N, 0, 0);


	return 0;
}
