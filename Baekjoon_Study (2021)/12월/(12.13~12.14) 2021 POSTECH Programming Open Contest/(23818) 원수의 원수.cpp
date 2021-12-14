#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 100001

int N, M, K;
vector<vector<pii>> Edge(MAX, vector<pii>());
vector<int> Relate(MAX);
vector<int> visited(MAX, 0);
vector<bool> is_Error(MAX, 0);

void DFS(int node, int prev, int vis) {
	FOR(i, 0, LEN(Edge[node]) - 1) {
		int next = Edge[node][i].first;
		int rela = Edge[node][i].second;
		if (next == prev) continue;
		if (visited[next]) {
			if ((rela == 0 && Relate[node] != Relate[next]) ||
				(rela == 1 && Relate[node] == Relate[next])) {
				is_Error[vis] = 1;
			}
		}
		else if (!visited[next]) {
			visited[next] = vis;
			if (rela == 0) {
				Relate[next] = Relate[node];
			}
			else if (rela == 1) {
				Relate[next] = 1 - Relate[node];
			}
			DFS(next, node, vis);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(m, 1, M) {
		int t, a, b;
		cin >> t >> a >> b;
		Edge[a].push_back({ b, t });
		Edge[b].push_back({ a, t });
	}
	int idx = 0;
	FOR(i, 1, N) {
		if (visited[i]) continue;
		idx++;
		visited[i] = idx;
		DFS(i, 0, idx);
	}
	FOR(k, 1, K) {
		int a, b;
		cin >> a >> b;
		if (visited[a] != visited[b]) {
			cout << "Unknown";
		}
		else if (visited[a] == visited[b]) {
			if (is_Error[visited[a]]) {
				cout << "Error";
			}
			else if (!is_Error[visited[a]]) {
				if (Relate[a] == Relate[b]) {
					cout << "Friend";
				}
				else if (Relate[a] != Relate[b]) {
					cout << "Enemy";
				}
			}
		}
		cout << "\n";
	}

	return 0;
}