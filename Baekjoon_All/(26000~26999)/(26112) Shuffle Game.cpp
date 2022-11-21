#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 501

int n, p, q;
vector<string> X(MAX), P(MAX), Q(MAX);
vector<vector<vector<int>>> dp(MAX, vector<vector<int>>(MAX, vector<int>(MAX, -1)));

int DP(int a, int b, int c) {
	if (a <= 0 || b < 0 || c < 0) {
		return 0;
	}
	int& ret = dp[a][b][c];
	if (ret != -1) {
		return ret;
	}
	ret = max({ DP(a - 1, b, c), DP(a, b - 1, c), DP(a, b, c - 1) });
	if (X[a] == P[b]) {
		ret = max(ret, DP(a - 1, b - 1, c) + 1);
	}
	if (X[a] == Q[c]) {
		ret = max(ret, DP(a - 1, b, c - 1) + 1);
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> n >> p >> q;
	FOR(i, 1, n) {
		cin >> X[i];
	}
	FOR(i, 1, p) {
		cin >> P[i];
	}
	FOR(i, 1, q) {
		cin >> Q[i];
	}

	cout << DP(n, p, q);

	return 0;
}