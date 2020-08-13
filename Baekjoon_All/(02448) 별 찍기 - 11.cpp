#include <iostream>
#include <math.h>
using namespace std;

bool arr[3072][6143];

void star(int n, int y, int x) {
	if (n == 3) {
		arr[y][x] = 1;
		arr[y + 1][x - 1] = 1;
		arr[y + 1][x] = 0;
		arr[y + 1][x + 1] = 1;
		arr[y + 2][x - 2] = 1;
		arr[y + 2][x - 1] = 1;
		arr[y + 2][x] = 1;
		arr[y + 2][x + 1] = 1;
		arr[y + 2][x + 2] = 1;
		return;
	}
	star(n / 2, y, x);
	star(n / 2, y + n / 2, x - n / 2);
	star(n / 2, y + n / 2, x + n / 2);
}

int main() {
	int N;
	int step;
	cin >> N;
	step = sqrt(N / 3);
	star(N, 0, N - 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (arr[i][j] == 1)
				cout << '*';
			else if (arr[i][j] == 0)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}