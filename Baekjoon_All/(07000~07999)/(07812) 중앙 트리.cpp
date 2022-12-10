#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 10001

int N;
vector<vector<pll>> Edge;
vector<ll> cnt;
vector<ll> sum;
ll ans;

void Init(int node, int prev) {
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		ll cost = Edge[node][i].second;
		if (next == prev) continue;
		Init(next, node);
		cnt[node] += cnt[next];
		sum[node] += sum[next] + cnt[next] * cost;
	}
}

void DFS(int node, int prev) {
	ans = min(ans, sum[node]);
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		ll cost = Edge[node][i].second;
		if (next == prev) continue;
		sum[next] = sum[node] - cnt[next] * cost + (N - cnt[next]) * cost;
		DFS(next, node);
	}
}

int main() {
	FASTIO;
	while (true) {
		cin >> N;
		if (N == 0) break;
		Edge = vector<vector<pll>>(N, vector<pll>());
		cnt = vector<ll>(N, 1);
		sum = vector<ll>(N, 0);
		ans = LINF;
		FOR(i, 1, N - 1) {
			int a, b, w;
			cin >> a >> b >> w;
			Edge[a].push_back({ b, w });
			Edge[b].push_back({ a, w });
		}
		Init(0, -1);
		DFS(0, -1);
		cout << ans << "\n";
	}

	return 0;
}