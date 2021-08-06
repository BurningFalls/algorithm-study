#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

int N;
vector<int> edge[100001];
int dp[100001][19];

int DP(int node, int prev, int color) {
	int& ret = dp[node][color];
	if (ret != -1)
		return ret;
	ret = color;
	for(int next : edge[node]) {
		if (next == prev) continue;
		int mini = INF;
		FOR(ncolor, 1, 18) {
			if (color == ncolor) continue;
			mini = min(mini, DP(next, node, ncolor));
		}
		ret += mini;
	}
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int mini = INF;
	FOR(i, 1, 18) {
		mini = min(mini, DP(1, 0, i));
	}
	cout << mini;

	return 0;
}