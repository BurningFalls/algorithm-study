#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, E;
vector<int> v[20001];
int visited[20001] = { 0, };

void DFS(int node, int kind) {
	int new_node;
	int size = v[node].size();
	visited[node] = kind;
	for (int i = 0; i < size; i++) {
		new_node = v[node][i];
		if (visited[new_node]) continue;
		DFS(new_node, 3 - kind);
	}
}

bool Check() {
	for (int i = 1; i <= V; i++) {
		int size = v[i].size();
		for (int j = 0; j < size; j++) {
			int new_node = v[i][j];
			if (visited[i] == visited[new_node])
				return false;
		}
	}
	return true;
}

int main() {
	int K;
	int a, b;
	cin >> K;
	for (int T = 0; T < K; T++) {
		cin >> V >> E;
		for (int i = 1; i <= V; i++)
			v[i].clear();
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				DFS(i, 1);
			}
		}
		if (Check())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}