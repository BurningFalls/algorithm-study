#include <iostream>
#include <vector>
using namespace std;

// first: node, second: distance
vector<pair<int, int>> v[50001];
// first: depth, second: parent node
pair<int, int> inf[50001];
int visited[50001] = { 0, };
int dist[50001] = { 0, };

void Tree(int node) {
	int len;
	int new_node;
	bool flag = false;
	int d;
	len = v[node].size();
	for (int i = 0; i < len; i++) {
		new_node = v[node][i].first;
		d = v[node][i].second;
		if (visited[new_node]) continue;
		flag = true;
		visited[new_node] = visited[node] + 1;
		dist[new_node] = dist[node] + d;
		inf[new_node] = make_pair(visited[new_node], node);
		Tree(new_node);
	}
	if (!flag)
		return;
}

int Find(int node1, int node2) {
	int dep1, dep2;
	dep1 = inf[node1].first;
	dep2 = inf[node2].first;
	if (dep1 > dep2) {
		for (int i = 0; i < dep1 - dep2; i++)
			node1 = inf[node1].second;
	}
	else if (dep1 < dep2) {
		for (int i = 0; i < dep2 - dep1; i++)
			node2 = inf[node2].second;
	}
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
	int a, b, c;
	int same_node;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cin >> M;

	visited[1] = 1;
	inf[1] = make_pair(1, 0);
	Tree(1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		same_node = Find(a, b);
		cout << dist[a] + dist[b] - 2 * dist[same_node] << "\n";
	}

	return 0;
}