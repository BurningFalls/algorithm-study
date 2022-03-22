#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool Check(int N, int y, int x, vector<vector<char>>& Map) {
	if (Map[y][x] == '1') {
		return false;
	}
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	FOR(i, 0, 3) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (Map[ny][nx] == '1') {
			return false;
		}
	}
	return true;
}

int main() {
	FASTIO;
	int N, C, E;
	cin >> N >> C >> E;
	vector<vector<char>> Map(N, vector<char>(N, '0'));
	int c_cnt = 0, e_cnt = 0;
	FOR(diag, 0, N - 1) {
		FOR(i, 0, diag) {
			int j = diag - i;
			Map[i][j] = '1';
			c_cnt++;
			if (c_cnt == C) break;
		}
		if (c_cnt == C) break;
	}
	if (c_cnt != C) {
		FOR(diag, N, 2 * N - 2) {
			FOR(i, diag - N + 1, N - 1) {
				int j = diag - i;
				Map[i][j] = '1';
				c_cnt++;
				if (c_cnt == C) break;
			}
			if (c_cnt == C) break;
		}
	}
	bool flag = true;
	ROF(diag, 2 * N - 2, N) {
		ROF(i, N - 1, diag - N + 1) {
			int j = diag - i;
			Map[i][j] = '2';
			flag &= Check(N, i, j, Map);
			e_cnt++;
			if (e_cnt == E) break;
		}
		if (e_cnt == E) break;
	}
	if (e_cnt != E) {
		ROF(diag, N - 1, 0) {
			ROF(i, diag, 0) {
				int j = diag - i;
				Map[i][j] = '2';
				flag &= Check(N, i, j, Map);
				e_cnt++;
				if (e_cnt == E) break;
			}
			if (e_cnt == E) break;
		}
	}

	if (!flag) {
		cout << -1;
	}
	else {
		cout << 1 << "\n";
		FOR(i, 0, N - 1) {
			FOR(j, 0, N - 1) {
				cout << Map[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}