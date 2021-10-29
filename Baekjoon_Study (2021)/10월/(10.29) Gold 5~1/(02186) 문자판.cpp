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

int N, M, K;
char Map[101][101];
int dp[101][101][80];
string target;

int DP(int y, int x, int idx) {
	if (idx == LEN(target) - 1) {
		return 1;
	}
	int& ret = dp[y][x][idx];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	FOR(j, max(1, x - K), min(M, x + K)) {
		if (j == x) continue;
		if (Map[y][j] == target[idx + 1]) {
			ret += DP(y, j, idx + 1);
		}
	}
	FOR(i, max(1, y - K), min(N, y + K)) {
		if (i == y) continue;
		if (Map[i][x] == target[idx + 1]) {
			ret += DP(i, x, idx + 1);
		}
	}
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}
	cin >> target;
	int ans = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == target[0]) {
				ans += DP(i, j, 0);
			}
		}
	}
	cout << ans;

	return 0;
}