#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;
int visited[100001] = { 0, };

int BFS() {
	int node;
	int nd[3];
	while (!q.empty()) {
		node = q.front();
		if (node == K)
			return visited[node] - 1;
		q.pop();
		nd[0] = node - 1;
		nd[1] = node + 1;
		nd[2] = node * 2;
		for (int i = 0; i < 3; i++) {
			if (nd[i] >= 0 && nd[i] <= 100000) {
				if (visited[nd[i]] == 0) {
					visited[nd[i]] = visited[node] + 1;
					q.push(nd[i]);
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;
	q.push(N);
	visited[N] = 1;
	cout << BFS();

	return 0;
}