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
#define MAX 1000001

int N;
vector<vector<int>> Edge(MAX, vector<int>());
vector<ll> dp(MAX);
vector<ll> ans(MAX, 0);

int DFS(int node, int prev) {
	int cnt = 1;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		cnt += DFS(next, node);
	}
	return dp[node] = cnt;
}

void Travel(int node, int prev) {
	int tmp = dp[node];
	ans[node] += dp[node] * (N - dp[node]);
	for (int next : Edge[node]) {
		if (next == prev) continue;
		dp[node] = N - dp[next];
		ans[node] += dp[node] * dp[next];
		Travel(next, node);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		int x, y;
		cin >> x >> y;
		Edge[x].push_back(y);
		Edge[y].push_back(x);
	}
	DFS(1, 0);
	dp[1] = N - 1;
	Travel(1, 0);

	FOR(i, 1, N) {
		if (i != 1) {
			ans[i] += N - 1;
		}
		cout << ans[i] << "\n";
	}

	return 0;
}