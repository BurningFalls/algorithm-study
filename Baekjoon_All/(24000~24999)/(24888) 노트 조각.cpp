#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, ll>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 200001

int N, M;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<int> A(MAX);
vector<ll> Dist(MAX, LINF);
vector<int> A_cnt(MAX, 0);
vector<int> Route;
int A_sum = 0;

void DT() {
	PQ<pair<ll, int>> pq;
	pq.push({ 0, 1 });
	A_cnt[1] = A[1];
	Dist[1] = 0;
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (Dist[cur] < cost) continue;
		FOR(i, 0, LEN(Edge[cur]) - 1) {
			int next = Edge[cur][i].first;
			ll ncost = Edge[cur][i].second + cost;
			if (Dist[next] > ncost) {
				Dist[next] = ncost;
				A_cnt[next] = max(A_cnt[next], A_cnt[cur] + A[next]);
				pq.push({ -Dist[next], next });
			}
			else if (Dist[next] == ncost) {
				A_cnt[next] = max(A_cnt[next], A_cnt[cur] + A[next]);
			}
		}
	}
}

void DFS(int node, int prev) {
	if (node == 1) {
		cout << LEN(Route) << "\n";
		ROF(i, LEN(Route) - 1, 0) {
			cout << Route[i] << " ";
		}
		exit(0);
	}
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		int cost = Edge[node][i].second;
		if (next == prev) continue;
		if (Dist[next] + cost != Dist[node]) continue;
		if (A_cnt[next] + A[node] != A_cnt[node]) continue;
		Route.push_back(next);
		DFS(next, node);
		Route.pop_back();
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int u, v, w;
		cin >> u >> v >> w;
		Edge[u].push_back({ v, w });
		Edge[v].push_back({ u, w });
	}
	FOR(i, 1, N) {
		cin >> A[i];
		A_sum += A[i];
	}

	DT();

	if (A_cnt[N] != A_sum) {
		cout << -1;
		return 0;
	}

	Route.push_back(N);
	DFS(N, 0);

	return 0;
}