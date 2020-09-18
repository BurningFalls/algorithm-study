#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
queue<int> q;
bool visited[101] = { 0, };

void BFS() {
	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			if (visited[v[node][i]]) continue;
			visited[v[node][i]] = 1;
			q.push(v[node][i]);
		}
	}
}

int main() {
	int N;
	int M;
	int x, y;
	int cnt = 0;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(1);
	visited[1] = 1;
	BFS();
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1)
			cnt++;
	}
	cout << cnt - 1;

	return 0;
}