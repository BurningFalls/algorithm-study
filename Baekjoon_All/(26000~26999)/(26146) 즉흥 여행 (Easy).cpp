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
#define MAX 200001

int N, M;
vector<vector<int>> Edge(MAX, vector<int>());
vector<int> visited(MAX, 0);
vector<bool> finished(MAX, 0);
vector<int> route;
vector<vector<int>> scc;
int idx = 1;

int DFS(int node) {
	visited[node] = idx;
	idx += 1;
	route.push_back(node);
	int minimum = visited[node];
	for(int next : Edge[node]) {
		if (!visited[next]) {
			minimum = min(minimum, DFS(next));
		}
		else if (visited[next] && !finished[next]) {
			minimum = min(minimum, visited[next]);
		}
	}

	if (minimum == visited[node]) {
		vector<int> tmp;
		while (true) {
			int t = route.back();
			route.pop_back();
			tmp.push_back(t);
			finished[t] = 1;
			if (t == node)
				break;
		}
		scc.push_back(tmp);
	}
	return minimum;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int A, B;
		cin >> A >> B;
		Edge[A].push_back(B);
	}
	FOR(i, 1, N) {
		if (visited[i]) continue;
		DFS(i);
	}

	cout << (scc.size() == 1 && scc[0].size() == N ? "Yes" : "No");

	return 0;
}