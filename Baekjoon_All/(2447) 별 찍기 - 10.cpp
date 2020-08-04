#include <iostream>
using namespace std;

char arr[2187][2187];

void star(int n, int x, int y) {
	if (n == 1) {
		arr[x][y] = '*';
	}
	else {
		star(n / 3, x, y);
		star(n / 3, x, y + n / 3);
		star(n / 3, x, y + n * 2 / 3);
		star(n / 3, x + n / 3, y);
		star(n / 3, x + n / 3, y + n * 2 / 3);
		star(n / 3, x + n * 2 / 3, y);
		star(n / 3, x + n * 2 / 3, y + n / 3);
		star(n / 3, x + n * 2 / 3, y + n * 2 / 3);
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 2187; i++) {
		for (int j = 0; j < 2187; j++) {
			arr[i][j] = ' ';
		}
	}
	star(N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}