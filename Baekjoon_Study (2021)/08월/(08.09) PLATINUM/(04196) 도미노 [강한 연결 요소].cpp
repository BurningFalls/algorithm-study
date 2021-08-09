#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100001

int N, M;
vector<int> edge[MAX];
int scc_num[MAX];
int visited[MAX];
int finished[MAX];
int scc_idx;
int visited_idx;
vector<int> stored_v;
int indegree[MAX];

int DFS(int node) {
	visited[node] = ++visited_idx;
	stored_v.push_back(node);
	int mini = visited[node];
	for (int next : edge[node]) {
		if (!visited[next]) {
			mini = min(mini, DFS(next));
		}
		else if (!finished[next]) {
			mini = min(mini, visited[next]);
		}
	}

	if (mini == visited[node]) {
		scc_idx++;
		while (true) {
			int n = stored_v.back();
			stored_v.pop_back();
			scc_num[n] = scc_idx;
			finished[n] = 1;
			if (n == node)
				break;
		}
	}
	return mini;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		stored_v.clear();
		scc_idx = 0;
		visited_idx = 0;
		FOR(i, 1, N) {
			edge[i].clear();
			visited[i] = 0;
			finished[i] = 0;
			scc_num[i] = 0;
			indegree[i] = 0;
		}
		FOR(i, 1, M) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
		}
		FOR(i, 1, N) {
			if (visited[i]) continue;
			DFS(i);
		}
		FOR(A, 1, N) {
			for (int B : edge[A]) {
				if (scc_num[A] == scc_num[B]) continue;
				indegree[scc_num[B]]++;
			}
		}
		int cnt = 0;
		FOR(i, 1, scc_idx) {
			if (indegree[i] == 0)
				cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}