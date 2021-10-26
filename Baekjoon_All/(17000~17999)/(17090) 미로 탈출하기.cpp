#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, M;
char Map[501][501];
int DP[501][501];
char Letter[4] = { 'U', 'R', 'D', 'L' };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int DPF(int y, int x) {
	if (y < 1 || x < 1 || y > N || x > M) {
		return 1;
	}
	int& ret = DP[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	int idx = 0;
	FOR(i, 0, 3) {
		if (Map[y][x] == Letter[i]) {
			idx = i;
		}
	}
	int ny = y + dy[idx];
	int nx = x + dx[idx];
	ret |= DPF(ny, nx);
	return ret;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			DP[i][j] = -1;
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			DPF(i, j);
		}
	}
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cnt += DP[i][j];
		}
	}
	cout << cnt;

	return 0;
}