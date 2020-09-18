#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[1001];
int visited[1001] = { 0, };

void dfs(int node) {
	visited[node] = 1;
	for (int i = 0; i < edge[node].size(); i++) {
		if (!visited[edge[node][i]]) {
			dfs(edge[node][i]);
		}
	}
}

int main() {
	int N, M;
	int u, v;
	int group = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			group++;
			dfs(i);
		}
	}
	cout << group << endl;

	return 0;
}