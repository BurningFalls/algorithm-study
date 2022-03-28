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
vector<int> Route(MAX);
int note_sum = 0;

void DT() {
	PQ<pair<ll, int>> pq;
	pq.push({ 0, 1 });
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
				pq.push({ -Dist[next], next });
			}
		}
	}
}

void BT(int cur, int idx, int sum) {
	Route[idx] = cur;
	if (cur == N) {
		if (sum == note_sum) {
			cout << idx + 1 << "\n";
			FOR(i, 0, idx) {
				cout << Route[i] << " ";
			}
			exit(0);
		}
		return;
	}
	FOR(i, 0, LEN(Edge[cur]) - 1) {
		int next = Edge[cur][i].first;
		ll cost = Edge[cur][i].second;
		if (Dist[cur] + cost == Dist[next]) {
			BT(next, idx + 1, sum + A[next]);
		}
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
		note_sum += A[i];
	}

	DT();
	BT(1, 0, A[1]);
	cout << -1;

	return 0;
}