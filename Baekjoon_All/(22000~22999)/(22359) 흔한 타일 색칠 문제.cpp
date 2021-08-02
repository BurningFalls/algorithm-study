#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[1026][1026];

void Func(int size, int y, int x, int pos, bool is_alpha, int a, int b) {
	if (size == 2) {
		if (is_alpha) {
			FOR(i, y, y + 1) {
				FOR(j, x, x + 1) {
					if (arr[i][j] == 'c') continue;
					if (pos == 1 || pos == 4)
						arr[i][j] = 'a';
					else if (pos == 2 || pos == 3)
						arr[i][j] = 'b';
				}
			}
		}
		else {
			if (pos == 1) {
				arr[y][x] = 'a';
				arr[y][x + 1] = 'a';
				arr[y + 1][x] = 'a';
				arr[y + 1][x + 1] = 'c';
			}
			else if (pos == 2) {
				arr[y][x] = 'b';
				arr[y][x + 1] = 'b';
				arr[y + 1][x] = 'c';
				arr[y + 1][x + 1] = 'b';
			}
			else if (pos == 3) {
				arr[y][x] = 'b';
				arr[y][x + 1] = 'c';
				arr[y + 1][x] = 'b';
				arr[y + 1][x + 1] = 'b';
			}
			else if (pos == 4) {
				arr[y][x] = 'c';
				arr[y][x + 1] = 'a';
				arr[y + 1][x] = 'a';
				arr[y + 1][x + 1] = 'a';
			}
		}
		return;
	}
	if (!is_alpha) {
		if (pos == 1) {
			arr[y + size - 1][x + size - 1] = 'c';
			Func(size / 2, y, x, 1, 0, a, b);
			Func(size / 2, y, x + size / 2, 2, 0, a, b);
			Func(size / 2, y + size / 2, x, 3, 0, a, b);
			Func(size / 2, y + size / 2, x + size / 2, 4, 1, y + size - 1, x + size - 1);
		}
		else if (pos == 2) {
			arr[y + size - 1][x] = 'c';
			Func(size / 2, y, x, 1, 0, a , b);
			Func(size / 2, y, x + size / 2, 2, 0, a, b);
			Func(size / 2, y + size / 2, x, 3, 1, y + size - 1, x);
			Func(size / 2, y + size / 2, x + size / 2, 4, 0, a, b);
		}
		else if (pos == 3) {
			arr[y][x + size - 1] = 'c';
			Func(size / 2, y, x, 1, 0, a, b);
			Func(size / 2, y, x + size / 2, 2, 1, y, x + size - 1);
			Func(size / 2, y + size / 2, x, 3, 0, a, b);
			Func(size / 2, y + size / 2, x + size / 2, 4, 0, a, b);
		}
		else if (pos == 4) {
			arr[y][x] = 'c';
			Func(size / 2, y, x, 1, 1, y, x);
			Func(size / 2, y, x + size / 2, 2, 0, a, b);
			Func(size / 2, y + size / 2, x, 3, 0, a, b);
			Func(size / 2, y + size / 2, x + size / 2, 4, 0, a, b);
		}
	}
	else if (is_alpha) {
		Func(size / 2, y, x, 1, (a >= y && a < y + size / 2 && b >= x && b < x + size / 2), a, b);
		Func(size / 2, y, x + size / 2, 2, (a >= y && a < y + size / 2 && b >= x + size / 2 && b < x + size), a, b);
		Func(size / 2, y + size / 2, x, 3, (a >= y + size / 2 && a < y + size && b >= x && b < x + size / 2), a, b);
		Func(size / 2, y + size / 2, x + size / 2, 4, (a >= y + size / 2 && a < y + size && b >= x + size / 2 && b < x + size), a, b);
	}
}

void Print(int size) {
	FOR(i, 1, size) {
		FOR(j, 1, size) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

int main() {
	FASTIO;
	int T, K;
	cin >> T >> K;
	int size = pow(2, K);
	while (T--) {
		int a, b;
		FOR(i, 1, size) {
			FOR(j, 1, size) {
				arr[i][j] = '.';
			}
		}
		cin >> a >> b;
		arr[a][b] = 'c';
		Func(size, 1, 1, 1, 1, a, b);
		arr[a][b] = '@';
		Print(size);
	}


	return 0;
}