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
#define MAX 100001

int N, K;
vector<vector<int>> Edge(MAX, vector<int>());
vector<int> lens;
int maxi = 0;
int max_node = 0;

void Move(int node, int prev, int len) {
	if (maxi < len) {
		maxi = len;
		max_node = node;
	}
	for (int next : Edge[node]) {
		if (next == prev) continue;
		Move(next, node, len + 1);
	}
}

int DFS(int node, int prev) {
	vector<int> tmp;
	int maxi = 0;
	for (int next : Edge[node]) {
		if (next == prev) continue;
		int x = DFS(next, node);
		tmp.push_back(x);
		maxi = max(maxi, x);
	}
	bool flag = false;
	FOR(i, 0, LEN(tmp) - 1) {
		if (!flag && tmp[i] == maxi) {
			flag = true;
			continue;
		}
		lens.push_back(tmp[i]);
	}
	return maxi + 1;
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	Move(1, 0, 1);
	ll ans = DFS(max_node, 0) - 1;
	sort(ALL(lens), greater<int>());
	FOR(i, 0, min(K, LEN(lens)) - 1) {
		ans += lens[i];
	}
	cout << ans;

	return 0;
}