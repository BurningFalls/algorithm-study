#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 987654321

int Map[10];
int ch_Map[10];
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

void Activate(int y, int x) {
	FOR(i, 0, 4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10) continue;
		ch_Map[ny] ^= (1 << nx);
	}
}

int main() {
	FASTIO;
	char x;
	FOR(i, 0, 9) {
		FOR(j, 0, 9) {
			cin >> x;
			if (x == 'O')
				Map[i] |= (1 << j);
		}
	}
	int cnt;
	int ans = INF;
	FOR(st, 0, (1 << 10) - 1) {
		cnt = 0;
		FOR(i, 0, 9)
			ch_Map[i] = Map[i];
		FOR(i, 0, 9) {
			if (st & (1 << i)) {
				Activate(0, i);
				cnt++;
			}
		}
		FOR(i, 1, 9) {
			FOR(j, 0, 9) {
				if (ch_Map[i - 1] & (1 << j)) {
					Activate(i, j);
					cnt++;
				}
			}
		}
		if (ch_Map[9] == 0)
			ans = min(ans, cnt);
	}
	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}