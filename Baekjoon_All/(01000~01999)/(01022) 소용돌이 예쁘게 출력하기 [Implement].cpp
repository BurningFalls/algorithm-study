#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Map[52][7];
int ans[52][7];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
	FASTIO;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int N = r2 - r1;
	int M = c2 - c1;
	int y = -r1;
	int x = -c1;
	int idx = 1;
	int cnt = 0;
	int len = 1;
	int is_two = 0;
	int d = 0;
	int total_cnt = 0;
	while (total_cnt < (N + 1) * (M + 1)) {
		if (y >= 0 && x >= 0 && y <= N && x <= M) {
			ans[y][x] = idx;
			total_cnt++;
		}
		y += dy[d];
		x += dx[d];
		cnt++;
		idx++;
		if (cnt == len) {
			cnt = 0;
			d = (d + 1) % 4;
			is_two++;
			if (is_two == 2) {
				is_two = 0;
				len++;
			}
		}
	}
	idx--;
	int max_len = to_string(idx).size();
	FOR(i, 0, N) {
		FOR(j, 0, M) {
			int len = to_string(ans[i][j]).size();
			FOR(k, 1, max_len - len)
				cout << " ";
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}