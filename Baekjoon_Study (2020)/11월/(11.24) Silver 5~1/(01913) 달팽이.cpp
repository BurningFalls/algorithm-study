#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, X;
int X_y, X_x;
int arr[1001][1001];

void is_X(int y, int x, int num) {
	if (num == X) {
		X_y = y;
		X_x = x;
	}
}

int main() {
	FASTIO;
	cin >> N >> X;
	int num = 1;
	int size = 1;
	int y = 500;
	int x = 500;
	arr[y][x] = num;
	is_X(y, x, num);
	num++;
	size++;
	while (size <= N) {
		if (size % 2 == 0) {
			y--;
			arr[y][x] = num;
			is_X(y, x, num);
			FOR(i, 1, size - 1) {
				x++;
				num++;
				arr[y][x] = num;
				is_X(y, x, num);
			}
			FOR(i, 1, size - 1) {
				y++;
				num++;
				arr[y][x] = num;
				is_X(y, x, num);
			}
		}
		else if (size % 2 == 1) {
			y++;
			arr[y][x] = num;
			is_X(y, x, num);
			FOR(i, 1, size - 1) {
				x--;
				num++;
				arr[y][x] = num;
				is_X(y, x, num);
			}
			FOR(i, 1, size - 1) {
				y--;
				num++;
				arr[y][x] = num;
				is_X(y, x, num);
			}
		}
		num++;
		size++;
	}
	size--;
	if (N % 2 == 0) {
		X_y -= 500 - (N / 2 + 1);
		X_x -= 500 - N / 2;
	}
	else if (N % 2 == 1) {
		X_y -= 500 - (N / 2 + 1);
		X_x -= 500 - (N / 2 + 1);
	}
	int start_y = 0, start_x = 0;
	if (size % 2 == 1) {
		start_y = y;
		start_x = x;
	}
	else if (size % 2 == 0) {
		start_y = y - (size - 1);
		start_x = x - (size - 1);
	}
	FOR(i, start_y, start_y + (size - 1)) {
		FOR(j, start_x, start_x + (size - 1)) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << X_y << " " << X_x;

	return 0;
}