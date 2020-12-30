#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int W[10001];
vector<int> edge[10001];
int dp[10002][2];
vector<int> ans;

int DFS(int prev, int node, bool flag) {
	int& ret = dp[node][flag];
	if (ret != -1)
		return ret;
	if (flag)
		ret = W[node];
	else
		ret = 0;
	int len = edge[node].size();
	FOR(i, 0, len - 1) {
		int next = edge[node][i];
		if (next == prev) continue;
		if (flag)
			ret += DFS(node, next, 0);
		else
			ret += max(DFS(node, next, 0), DFS(node, next, 1));
	}
	return ret;
}

void Trace(int prev, int node, bool flag) {
	if (flag) {
		ans.push_back(node);
		int len = edge[node].size();
		FOR(i, 0, len - 1) {
			int next = edge[node][i];
			if (next == prev) continue;
			Trace(node, next, 0);
		}
	}
	else {
		int len = edge[node].size();
		FOR(i, 0, len - 1) {
			int next = edge[node][i];
			if (next == prev) continue;
			if (dp[next][1] >= dp[next][0])
				Trace(node, next, 1);
			else
				Trace(node, next, 0);
		}
	}
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	FOR(i, 1, N)
		cin >> W[i];
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int first = DFS(0, 1, 0);
	int second = DFS(0, 1, 1);
	if (first >= second)
		Trace(0, 1, 0);
	else
		Trace(0, 1, 1);
	sort(ans.begin(), ans.end());
	cout << max(first, second) << "\n";
	int len = ans.size();
	FOR(i, 0, len - 1)
		cout << ans[i] << " ";

	return 0;
}