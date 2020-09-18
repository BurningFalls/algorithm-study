#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, M, dist[20001] = { 0 }, d = 0, m = -1, dest = 20001, cnt = 0;
vector<int> child[20001];
queue<int> q;
void BFS() {
	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < child[node].size(); i++) {
			if (dist[child[node][i]]) continue;
			dist[child[node][i]] = dist[node] + 1;
			m = max(m, dist[child[node][i]]);
			q.push(child[node][i]);
		}
	}
}
int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		child[a].push_back(b);
		child[b].push_back(a);
	}
	q.push(1);
	dist[1] = 1;
	BFS();
	for (int i = 1; i <= N; i++) {
		if (dist[i] == m) {
			dest = min(i, dest);
			cnt++;
		}
	}
	cout << dest << " " << m - 1 << " " << cnt << "\n";
	return 0;
}