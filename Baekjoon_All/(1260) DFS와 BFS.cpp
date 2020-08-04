#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> edge[1001];
bool visited[1001] = { 0, };

void dfs(int node) {
	cout << node << " ";
	for (int i = 0; i < edge[node].size(); i++) {
		if (visited[edge[node][i]]) continue;
		visited[edge[node][i]] = 1;
		dfs(edge[node][i]);
	}
}

void bfs() {
	queue<int> q;
	q.push(V);
	visited[V] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (int i = 0; i < edge[node].size(); i++) {
			if (visited[edge[node][i]]) continue;
			visited[edge[node][i]] = 1;
			q.push(edge[node][i]);
		}
	}
}

int main() {
	int node1, node2;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
	}
	for (int i = 1; i <= N; i++) {
		sort(edge[i].begin(), edge[i].end());
	}

	//dfs
	visited[V] = 1;
	dfs(V);
	cout << endl;

	//bfs

	for (int i = 1; i <= 1000; i++) {
		visited[i] = 0;
	}
	bfs();

	return 0;
}