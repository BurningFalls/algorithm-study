#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> rela[501];
int visited[501] = { 0, };
queue<int> q;

void BFS() {
	int node, new_node;
	int len;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (visited[node] == 4) {
			break;
		}
		len = rela[node].size();
		for (int i = 0; i < len; i++) {
			new_node = rela[node][i];
			if (visited[new_node]) continue;
			visited[new_node] = visited[node] + 1;
			q.push(new_node);
		}
	}
}

int main() {
	int N, M;
	int a, b;
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		rela[a].push_back(b);
		rela[b].push_back(a);
	}
	visited[1] = 1;
	q.push(1);
	BFS();

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 2 || visited[i] == 3)
			ans++;
	}
	cout << ans;

	return 0;
}