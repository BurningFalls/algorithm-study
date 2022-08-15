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
#define MAX 100001

int N;
vector<int> P(MAX);
vector<ll> cnt(MAX, 1);
vector<vector<int>> Edge(MAX, vector<int>());

int Find(int node) {
	if (P[node] == node)
		return node;
	int p = Find(P[node]);
	return P[node] = p;
}

void Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	if (n1 == n2) return;
	P[n1] = n2;
	cnt[n2] += cnt[n1];
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		P[i] = i;
	}
	vector<ll> A(N + 1);
	vector<pll> v;
	FOR(i, 1, N) {
		cin >> A[i];
		v.push_back({ A[i], i });
	}
	sort(ALL(v));
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
		Edge[v].push_back(u);
	}

	ll ans = 0;
	ROF(i, N - 1, 0) {
		int cur = v[i].second;
		for (int next : Edge[cur]) {
			if (A[next] < A[cur]) continue;
			Union(cur, next);
		}
		ans = max(ans, A[cur] * cnt[Find(cur)]);
	}
	cout << ans;

	return 0;
}