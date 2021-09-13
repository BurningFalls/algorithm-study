#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

char Map[901][901];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, 3 * N) {
		FOR(j, 1, 3 * M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			int y = 3 * (i - 1) + 2;
			int x = 3 * (j - 1) + 2;
			if (Map[y][x] == '#') continue;
			Map[y][x] = '#';
			bool flag = false;
			FOR(k, 0, 3) {
				int ny = y + 2 * dy[k];
				int nx = x + 2 * dx[k];
				if (ny < 1 || nx < 1 || ny > 3 * N || nx > 3 * M) continue;
				if (Map[ny][nx] == '#') {
					Map[ny - dy[k]][nx - dx[k]] = '#';
					flag = true;
				}
			}
		}
	}

	FOR(i, 1, 3 * N) {
		FOR(j, 1, 3 * M) {
			cout << Map[i][j];
		}
		cout << "\n";
	}


	return 0;
}