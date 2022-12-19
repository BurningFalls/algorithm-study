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
#define MAX 1001

int N, M;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<int> dist(MAX, INF);
vector<int> dp(MAX, -1);

void DT() {
	PQ<pii> pq;
	dist[2] = 0;
	pq.push({ 0, 2 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			int ncost = cost + Edge[node][i].second;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int DFS(int node, int prev) {
	int& ret = dp[node];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		if (next == prev) continue;
		if (dist[node] > dist[next]) {
			ret += DFS(next, node);
		}
	}
	return ret;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back({ B, C });
		Edge[B].push_back({ A, C });
	}
	DT();
	dp[2] = 1;
	cout << DFS(1, 0);

	return 0;
}