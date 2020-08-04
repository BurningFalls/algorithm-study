#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100001];
int h[100001];
vector<int> v[100001];
int visited[100001];

void DFS(int node) {
	int len = v[node].size();
	bool flag = false;
	for (int i = 0; i < len; i++) {
		int new_node = v[node][i];
		if (visited[new_node]) continue;
		flag = true;
		visited[new_node] += 1;
		DFS(new_node);
	}
	if (!flag)
		return;
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			visited[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		for (int i = 1; i <= n; i++)
			cin >> h[i];
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			if (p[i] == 0) continue;
			DFS(1);
		}
	}


	return 0;
}