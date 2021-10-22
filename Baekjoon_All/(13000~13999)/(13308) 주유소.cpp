#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, M;
ll DP[2501][2501];
int Cost[2501];
vector<vector<pii>> Edge(2501, vector<pii>());
PQ<pair<ll, pii>> pq;

int DT() {
	pq.push({ 0, {1, Cost[1]} });
	DP[1][Cost[1]] = 0;
	while (!pq.empty()) {
		ll dp = -pq.top().first;
		int node = pq.top().second.first;
		int cost = pq.top().second.second;
		pq.pop();
		if (DP[node][cost] < dp) continue;
		if (node == N)
			return dp;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			ll ndist = dp + cost * Edge[node][i].second;
			int ncost = min(cost, Cost[next]);
			if (DP[next][cost] > ndist) {
				DP[next][cost] = ndist;
				pq.push({ -ndist, {next, ncost} });
			}
		}
	}
}

int main() {
	FASTIO;
	FOR(i, 1, 2500) {
		FOR(j, 0, 2500) {
			DP[i][j] = LINF;
		}
	}
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> Cost[i];
	}
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge[a].push_back({ b, c });
		Edge[b].push_back({ a, c });
	}
	cout << DT();

	return 0;
}