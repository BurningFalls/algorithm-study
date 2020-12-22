#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[104][104] = { 0, };
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int main() {
	FASTIO;
	int y = 52, x = 52;
	int dir = 0;
	int N;
	cin >> N;
	arr[y][x] = 1;
	FOR(i, 1, N) {
		char c;
		cin >> c;
		if (c == 'R') {
			dir = (dir + 1) % 4;
		}
		else if (c == 'L') {
			dir = (dir + 3) % 4;
		}
		else if (c == 'F') {
			y += dy[dir];
			x += dx[dir];
			arr[y][x] = 1;
		}
	}
	int col_s = 0, col_e = 0;
	int row_s = 0, row_e = 0;
	bool flag = false;
	FOR(i, 0, 103) {
		FOR(j, 0, 103) {
			if (!flag && arr[i][j] == 1) {
				col_s = i;
				flag = true;
			}
			if (arr[i][j] == 1)
				col_e = i;
		}
	}
	flag = false;
	FOR(i, 0, 103) {
		FOR(j, 0, 103) {
			if (!flag && arr[j][i] == 1) {
				row_s = i;
				flag = true;
			}
			if (arr[j][i] == 1)
				row_e = i;
		}
	}
	FOR(i, col_s, col_e) {
		FOR(j, row_s, row_e) {
			if (arr[i][j] == 1)
				cout << '.';
			else
				cout << "#";
		}
		cout << "\n";
	}

	return 0;
}