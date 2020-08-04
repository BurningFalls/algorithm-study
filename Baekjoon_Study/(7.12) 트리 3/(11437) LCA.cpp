#include <iostream>
#include <vector>
using namespace std;

vector<int> v[50001];
// first: depth, second: parent node
pair<int, int> inf[50001];
int visited[50001] = { 0, };

void Tree(int node) {
	int len;
	int new_node;
	bool flag = false;
	len = v[node].size();
	for (int i = 0; i < len; i++) {
		new_node = v[node][i];
		if (visited[new_node]) continue;
		flag = true;
		visited[new_node] = visited[node] + 1;
		inf[new_node] = make_pair(visited[new_node], node);
		Tree(new_node);
	}
	if (!flag)
		return;
}

int Find(int node1, int node2) {
	int d1, d2, d;
	d1 = inf[node1].first;
	d2 = inf[node2].first;
	if (d1 > d2) {
		for (int i = 0; i < d1 - d2; i++)
			node1 = inf[node1].second;
	}
	else if (d1 < d2) {
		for (int i = 0; i < d2 - d1; i++)
			node2 = inf[node2].second;
	}
	d = inf[node1].first;
	while (true) {
		if (node1 == node2) {
			return node1;
		}
		node1 = inf[node1].second;
		node2 = inf[node2].second;
	}
}

int main() {
	int N, M;
	int a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> M;

	visited[1] = 1;
	inf[1] = make_pair(1, 0);
	Tree(1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << Find(a, b) << "\n";
	}

	return 0;
}