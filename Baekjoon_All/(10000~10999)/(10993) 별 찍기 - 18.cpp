#include <iostream>
using namespace std;

int height[11];
int width[11];
bool arr[1024][2046];

void func(int n, int y, int x) {
	if (n == 1) {
		arr[y][x] = 1;
		return;
	}
	if (n % 2 == 0) {
		for (int i = 0; i < width[n]; i++) {
			arr[y + 0][x + i] = 1;
		}
		for (int i = 1; i < height[n]; i++) {
			arr[y + i][x + i] = 1;
			arr[y + i][x + width[n] - 1 - i] = 1;
		}
		func(n - 1, y + 1, x + width[n] / 4 + 1);
	}
	else if (n % 2 == 1) {
		for (int i = 0; i < height[n] - 1; i++) {
			arr[y + i][x + width[n] / 2 - i] = 1;
			arr[y + i][x + width[n] / 2 + i] = 1;
		}
		for (int i = 0; i < width[n]; i++) {
			arr[y + height[n] - 1][x + i] = 1;
		}
		func(n - 1, y + height[n] / 2, x + width[n] / 4 + 1);
	}
}

int main() {
	int N;
	cin >> N;
	height[1] = 1;
	for (int i = 2; i <= N; i++) {
		height[i] = height[i - 1] * 2 + 1;
	}
	width[1] = 1;
	for (int i = 2; i <= N; i++) {
		width[i] = (width[i - 1] + 1) * 2 + 1;
	}

	func(N, 0, 0);

	if (N % 2 == 0) {
		for (int i = 0; i < height[N]; i++) {
			for (int j = 0; j < width[N] - i; j++) {
				if (arr[i][j] == 1)
					cout << '*';
				else if (arr[i][j] == 0)
					cout << ' ';
			}
			cout << endl;
		}
	}
	else if (N % 2 == 1) {
		for (int i = 0; i < height[N]; i++) {
			for (int j = 0; j <= width[N] / 2 + i; j++) {
				if (arr[i][j] == 1)
					cout << '*';
				else if (arr[i][j] == 0)
					cout << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}