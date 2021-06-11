#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main() {
	FASTIO;
	int ans[5];
	int heart_y = 0, heart_x = 0;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	int hy = 0, hx = 0;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int cnt = 0;
			FOR(k, 0, 3) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny <1 || nx < 1 || ny > N || nx > N) continue;
				if (Map[ny][nx] == '*')
					cnt++;
			}
			if (cnt == 4) {
				hy = i; hx = j;
			}
		}
	}
	int HY = hy, HX = hx;
	heart_y = HY; heart_x = HX;
	int cnt = 0;
	hx -= 1;
	while (hx >= 1 && Map[hy][hx] == '*') {
		cnt++;
		hx--;
	}
	ans[0] = cnt;

	hy = HY, hx = HX;
	cnt = 0;
	hx += 1;
	while (hx <= N && Map[hy][hx] == '*') {
		cnt++;
		hx++;
	}
	ans[1] = cnt;

	hy = HY, hx = HX;
	cnt = 0;
	hy += 1;
	while (hy <= N && Map[hy][hx] == '*') {
		cnt++;
		hy++;
	}
	ans[2] = cnt;

	HY = hy; HX = hx;
	hy = HY; hx = HX - 1;
	cnt = 0;
	while (hy <= N && Map[hy][hx] == '*') {
		cnt++;
		hy++;
	}
	ans[3] = cnt;

	hy = HY; hx = HX + 1;
	cnt = 0;
	while (hy <= N && Map[hy][hx] == '*') {
		cnt++;
		hy++;
	}
	ans[4] = cnt;

	cout << heart_y << " " << heart_x << "\n";
	FOR(i, 0, 4)
		cout << ans[i] << " ";


	return 0;
}