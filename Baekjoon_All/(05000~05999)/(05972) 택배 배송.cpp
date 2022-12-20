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
#define MAX 50001

int N, M;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<int> dist(MAX, INF);

void DT() {
	PQ<pii> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			int ncost = Edge[node][i].second + cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		Edge[a].push_back({ b, c });
		Edge[b].push_back({ a, c });
	}
	DT();
	cout << dist[N];

	return 0;
}