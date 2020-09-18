#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int A, B;
vector<int> v[101];
queue<int> q;
int visited[101] = { 0, };
int answer = -1;

void BFS() {
	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			if (visited[v[node][i]]) continue;
			if (v[node][i] == B) {
				answer = visited[node];
				break;
			}
			visited[v[node][i]] = visited[node] + 1;
			q.push(v[node][i]);
		}
		if (answer != -1)
			break;
	}
}

int main() {
	int N;
	int M;
	int x, y;
	cin >> N;
	cin >> A >> B;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(A);
	visited[A] = 1;
	BFS();
	cout << answer;

	return 0;
}