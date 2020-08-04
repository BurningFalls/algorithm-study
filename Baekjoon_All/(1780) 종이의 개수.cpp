#include <iostream>
using namespace std;

int map[2187][2187];
int mone_cnt = 0;
int zero_cnt = 0;
int one_cnt = 0;

void DQ(int n, int y, int x) {
	int a = 0, b = 0, c = 0;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (map[i][j] == -1)
				a++;
			else if (map[i][j] == 0)
				b++;
			else if (map[i][j] == 1)
				c++;
		}
	}
	if (a == n * n)
		mone_cnt++;
	else if (b == n * n)
		zero_cnt++;
	else if (c == n * n)
		one_cnt++;
	else {
		DQ(n / 3, y, x);
		DQ(n / 3, y, x + n / 3);
		DQ(n / 3, y, x + n * 2 / 3);
		DQ(n / 3, y + n / 3, x);
		DQ(n / 3, y + n / 3, x + n / 3);
		DQ(n / 3, y + n / 3, x + n * 2 / 3);
		DQ(n / 3, y + n * 2 / 3, x);
		DQ(n / 3, y + n * 2 / 3, x + n / 3);
		DQ(n / 3, y + n * 2 / 3, x + n * 2 / 3);
	}
}


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	DQ(N, 0, 0);
	cout << mone_cnt << "\n" << zero_cnt << "\n" << one_cnt;

	return 0;
}