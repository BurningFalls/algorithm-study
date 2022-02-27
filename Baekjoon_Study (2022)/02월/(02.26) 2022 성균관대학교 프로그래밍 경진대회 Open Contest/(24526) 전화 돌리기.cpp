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

int N, M;
vector<vector<int>> Edge(MAX, vector<int>());
vector<int> Possible(MAX, -1);
vector<int> visited(MAX, 0);

int DFS(int node) {
	int& ret = Possible[node];
	if (ret != -1) {
		return ret;
	}
	ret = true;
	for (int next : Edge[node]) {
		if (visited[next]) {
			ret &= false;
			continue;
		}
		visited[next] = 1;
		ret &= DFS(next);
		visited[next] = 0;
	}
	return ret;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(m, 1, M) {
		int u, v;
		cin >> u >> v;
		Edge[u].push_back(v);
	}
	FOR(i, 1, N) {
		if (Possible[i] != -1) continue;
		visited[i] = 1;
		DFS(i);
		visited[i] = 0;
	}
	int cnt = 0;
	FOR(i, 1, N) {
		cnt += Possible[i];
	}
	cout << cnt;

	return 0;
}