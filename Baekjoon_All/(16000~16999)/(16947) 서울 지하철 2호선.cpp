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
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int N;
vvi Edge(3001, vi());
vi visited(3001, 0);
vector<bool> Cycle(3001, 0);
queue<int> q;

int DFS(int node, int vis) {
	visited[node] = vis;
	for (int next : Edge[node]) {
		if (!visited[next]) {
			int tmp = DFS(next, vis + 1);
			if (tmp >= 1) {
				Cycle[node] = 1;
				if (tmp == node) {
					return 0;
				}
				else {
					return tmp;
				}
			}
		}
		else if (visited[node] > visited[next] + 1) {
			Cycle[node] = 1;
			return next;
		}
	}
	return 0;
}

void BFS() {
	fill(ALL(visited), -1);
	FOR(i, 1, N) {
		if (!Cycle[i]) continue;
		q.push(i);
		visited[i] = 0;
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : Edge[node]) {
			if (visited[next] != -1) continue;
			visited[next] = visited[node] + 1;
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		Edge[a].push_back(b);
		Edge[b].push_back(a);
	}
	DFS(1, 1);
	BFS();
	FOR(i, 1, N) {
		cout << visited[i] << " ";
	}

	return 0;
}