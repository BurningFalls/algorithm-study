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
#define MAX 300001

int N;
ll ans = 0;
vector<vector<int>> Edge(MAX, vector<int>());
vector<ll> cnt(MAX, 1);
vector<ll> sum(MAX, 0);

void Init(int node, int prev) {
	for (int next : Edge[node]) {
		if (next == prev) continue;
		Init(next, node);
		cnt[node] += cnt[next];
		sum[node] += sum[next] + 1 * cnt[next];
	}
}

void DFS(int node, int prev) {
	ans += sum[node];
	for (int next : Edge[node]) {
		if (next == prev) continue;
		sum[next] = sum[node] + N - cnt[next] - 1;
		DFS(next, node);
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
	Init(1, 0);
	DFS(1, 0);
	cout << ans / 2;

	return 0;
}