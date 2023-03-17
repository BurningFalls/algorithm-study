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

ll N, M;
vector<vector<vector<pll>>> Edge(2, vector<vector<pll>>(MAX, vector<pll>()));
vector<vector<ll>> Cnt(2, vector<ll>(MAX, 1));
vector<ll> mini(2, LINF);
vector<ll> min_idx(2, 0);

ll Calc(int idx, int node, int prev) {
	ll sum = 0;
	FOR(i, 0, LEN(Edge[idx][node]) - 1) {
		ll next = Edge[idx][node][i].first;
		ll ncost = Edge[idx][node][i].second;
		if (next == prev) continue;
		sum += Calc(idx, next, node) + Cnt[idx][next] * ncost;
		Cnt[idx][node] += Cnt[idx][next];
	}
	return sum;
}

void Travel(int idx, int node, int prev, ll sum) {
	if (mini[idx] > sum) {
		mini[idx] = sum;
		min_idx[idx] = node;
	}
	FOR(i, 0, LEN(Edge[idx][node]) - 1) {
		ll next = Edge[idx][node][i].first;
		ll ncost = Edge[idx][node][i].second;
		if (next == prev) continue;
		ll nsum = sum + ((idx == 0 ? N : M) - 2 * Cnt[idx][next]) * ncost;
		Travel(idx, next, node, nsum);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N - 1) {
		ll a, b, c;
		cin >> a >> b >> c;
		Edge[0][a].push_back({ b, c });
		Edge[0][b].push_back({ a, c });
	}
	cin >> M;
	FOR(i, 1, M - 1) {
		ll a, b, c;
		cin >> a >> b >> c;
		Edge[1][a].push_back({ b, c });
		Edge[1][b].push_back({ a, c });
	}

	ll tmp = Calc(0, 1, 0);
	Travel(0, 1, 0, tmp);
	tmp = Calc(1, 1, 0);
	Travel(1, 1, 0, tmp);

	FOR(i, 0, 1) {
		cout << min_idx[i] << " ";
	}
	cout << "\n";
	cout << mini[0] * M + mini[1] * N + N * M;

	return 0;
}