#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int R, S;
	char Map[51][51];
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	cin >> R >> S;
	FOR(i, 1, R) {
		FOR(j, 1, S) {
			cin >> Map[i][j];
		}
	}
	int maxi = 0;
	int py = 1, px = 1;
	FOR(y, 1, R) {
		FOR(x, 1, S) {
			if (Map[y][x] == 'o') continue;
			int cnt = 0;
			FOR(k, 0, 7) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny < 1 || nx < 1 || ny > R || nx > S) continue;
				if (Map[ny][nx] == '.') continue;
				cnt++;
			}
			if (maxi < cnt) {
				maxi = cnt;
				py = y;
				px = x;
			}
		}
	}
	Map[py][px] = 'o';
	int ans = 0;
	FOR(y, 1, R) {
		FOR(x, 1, S) {
			if (Map[y][x] == '.') continue;
			FOR(k, 0, 7) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny < 1 || nx < 1 || ny > R || nx > S) continue;
				if (Map[ny][nx] == '.') continue;
				ans++;
			}
		}
	}
	cout << ans / 2;

	return 0;
}