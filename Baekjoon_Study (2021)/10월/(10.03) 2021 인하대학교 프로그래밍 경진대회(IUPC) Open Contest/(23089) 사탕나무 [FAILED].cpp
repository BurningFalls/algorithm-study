#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int N, K;
vector<int> edge[100001];
int dp[100001][22] = { 0, };
int maxi = 0;

int DFS(int node, int prev, int depth) {
	int& ret = dp[node][depth];
	if (ret != 0)
		return ret;
	for (int next : edge[node]) {
		if (next == prev) continue;
		ret += DFS(next, node, depth - 1);
	}
	return ret;
}

void ReRooting(int node, int prev) {
	int sum = 0;
	FOR(i, 0, K)
		sum += dp[node][i];
	maxi = max(maxi, sum);
	for (int next : edge[node]) {
		if (next == prev) continue;
		FOR(i, 1, K + 1)
			dp[node][i] -= dp[next][i - 1];
		FOR(i, 1, K + 1)
			dp[next][i] += dp[node][i - 1];
		ReRooting(next, node);
		FOR(i, 1, K + 1)
			dp[next][i] -= dp[node][i - 1];
		FOR(i, 1, K + 1)
			dp[node][i] += dp[next][i - 1];
	}
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N)
		dp[i][0] = 1;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	FOR(i, 0, 21)
		DFS(1, 0, i);

	ReRooting(1, 0);

	cout << maxi;

	return 0;
}