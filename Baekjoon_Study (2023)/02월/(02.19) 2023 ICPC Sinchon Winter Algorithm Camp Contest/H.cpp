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
#define MAX 500001

int N;
vector<vector<int>> Edge(MAX, vector<int>());
vector<vector<int>> Color(MAX, vector<int>(3));
vector<vector<int>> dp(MAX, vector<int>(3, -1));
vector<int> ansv(MAX, -1);

int DP(int node, int prev, int c) {
	int& ret = dp[node][c];
	if (ret != -1) {
		return ret;
	}

	ret = Color[node][c];
	for (int next : Edge[node]) {
		if (next == prev) continue;
		int maxi = 0;
		FOR(nc, 0, 2) {
			if (nc == c) continue;
			maxi = max(maxi, DP(next, node, nc));
		}
		ret += maxi;
	}
	return ret;
}

void Move(int node, int prev, int c) {
	if (ansv[node] != -1) return;
	ansv[node] = c;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		int maxi = 0;
		FOR(nc, 0, 2) {
			if (nc == c) continue;
			maxi = max(maxi, dp[next][nc]);
		}
		FOR(nc, 0, 2) {
			if (nc == c) continue;
			if (maxi == dp[next][nc]) {
				Move(next, node, nc);
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	FOR(i, 1, N) {
		FOR(j, 0, 2) {
			cin >> Color[i][j];
		}
	}

	int ans = 0;
	int start = 0;
	FOR(i, 0, 2) {
		ans = max(ans, DP(1, 0, i));
	}
	FOR(i, 0, 2) {
		if (ans == dp[1][i]) {
			start = i;
		}
	}
	Move(1, 0, start);

	cout << ans << "\n";
	FOR(i, 1, N) {
		if (ansv[i] == 0) {
			cout << 'R';
		}
		else if (ansv[i] == 1) {
			cout << 'G';
		}
		else if (ansv[i] == 2) {
			cout << 'B';
		}
	}

	return 0;
}