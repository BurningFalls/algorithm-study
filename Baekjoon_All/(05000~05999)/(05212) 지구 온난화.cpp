#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

char Map[12][12];
char Ch_Map[12][12];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	FASTIO;
	int R, C;
	cin >> R >> C;
	FOR(i, 0, C + 1) {
		Map[0][i] = '.';
		Map[R + 1][i] = '.';
	}
	FOR(i, 0, R + 1) {
		Map[i][0] = '.';
		Map[i][C + 1] = '.';
	}
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (Map[i][j] == '.') {
				Ch_Map[i][j] = '.';
				continue;
			}
			int cnt = 0;
			FOR(k, 0, 3) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (Map[ny][nx] == '.')
					cnt++;
			}
			if (cnt >= 3)
				Ch_Map[i][j] = '.';
			else
				Ch_Map[i][j] = 'X';
		}
	}
	int min_y = R, max_y = 1;
	int min_x = C, max_x = 1;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (Ch_Map[i][j] == 'X') {
				min_y = min(min_y, i);
				max_y = max(max_y, i);
				min_x = min(min_x, j);
				max_x = max(max_x, j);
			}
		}
	}
	FOR(i, min_y, max_y) {
		FOR(j, min_x, max_x) {
			cout << Ch_Map[i][j];
		}
		cout << "\n";
	}

	return 0;
}