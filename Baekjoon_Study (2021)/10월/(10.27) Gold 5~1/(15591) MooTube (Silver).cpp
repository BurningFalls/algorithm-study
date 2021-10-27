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

int N, Q;
vector<vector<pii>> Edge(5001, vector<pii>());
bool visited[5001];

int BFS(int k, int v) {
	queue<pii> q;
	memset(visited, 0, sizeof(visited));
	q.push({ v, INF });
	visited[v] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int node = q.front().first;
		int mini = q.front().second;
		q.pop();
		if (mini != INF && mini >= k) {
			cnt++;
		}
		FOR(i, 0, LEN(Edge[node]) - 1) {
			int next = Edge[node][i].first;
			int dist = Edge[node][i].second;
			if (visited[next]) continue;
			visited[next] = 1;
			q.push({ next, min(mini, dist) });
		}
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N >> Q;
	FOR(i, 1, N - 1) {
		int p, q, r;
		cin >> p >> q >> r;
		Edge[p].push_back({ q, r });
		Edge[q].push_back({ p, r });
	}
	FOR(q, 1, Q) {
		int k, v;
		cin >> k >> v;
		cout << BFS(k, v) << "\n";
	}

	return 0;
}