#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 987654321

int DFS(int node, int not_use, vector<vector<pii>>& edge, vector<vector<int>>& wires, vector<bool>& visited) {
	visited[node] = 1;
	int cnt = 1;
	FOR(i, 0, LEN(edge[node]) - 1) {
		int next = edge[node][i].first;
		int idx = edge[node][i].second;
		if (visited[next]) continue;
		if (idx == not_use) continue;
		cnt += DFS(next, not_use, edge, wires, visited);
	}
	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = INF;
	vector<vector<pii>> edge(101);
	vector<bool> visited(101);
	FOR(i, 0, n - 2) {
		int u = wires[i][0];
		int v = wires[i][1];
		edge[u].push_back({ v, i });
		edge[v].push_back({ u, i });
	}
	FOR(i, 0, n - 2) {
		fill(ALL(visited), 0);
		vector<int> cnt;
		FOR(j, 1, n) {
			if (visited[j]) continue;
			cnt.push_back(DFS(j, i, edge, wires, visited));
		}
		answer = min(answer, abs(cnt[0] - cnt[1]));
	}
	return answer;
}