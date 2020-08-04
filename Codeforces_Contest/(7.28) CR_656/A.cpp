#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v[501];
int DFS_visited[501] = { 0, };
int cycle_visited[501] = { 0, };
int cyc[501];

void DFS(int node, int start, int cnt) {
	if (node == start) {

		return;
	}
	int len = v[node].size();
	for (int i = 0; i < len; i++) {
		int new_node = v[node][i];
		if (DFS_visited[new_node]) continue;
		DFS_visited[new_node] = 1;
		cyc[cnt] = new_node;
		DFS(new_node, start, cnt + 1);
	}
}

int main() {
	int num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			if (i == j) continue;
			v[i].push_back(j);
			v[j].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			DFS_visited[j] = 0;
		DFS_visited[i] = 1;
		cyc[1] = i;
		DFS(i, i, 2);
	}

	return 0;
}