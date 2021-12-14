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

int DP(int n, int m, vector<vector<int>>& dp) {
	if (m < 0) {
		return -1;
	}
	else if (m == 0) {
		return 0;
	}
	if (n == 0) {
		return (m == 0 ? 0 : -1);
	}
	if (n >= m) {
		return m;
	}
	int& ret = dp[n][m];
	if (ret != -2) {
		return ret;
	}
	ret = -1;
	int hanger[3] = { 3, 7, 15 };
	int dress[3] = { 2, 4, 0 };
	FOR(i, 0, 2) {
		if (m < hanger[i]) continue;
		int tmp = DP(n - 1, m - hanger[i], dp);
		if (tmp == -1) continue;
		ret = max(ret, tmp + dress[i]);
	}
	return ret;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, -2));

	cout << DP(N, M, dp);

	return 0;
}