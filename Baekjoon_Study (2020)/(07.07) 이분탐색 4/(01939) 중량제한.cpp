#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[100001];
int N, M;
int start_node, end_node;

bool BFS(int bound) {
	bool visited[100001] = { 0, };
	queue<int> q;
	int node, new_node;
	int len;
	int limit;
	visited[start_node] = 1;
	q.push(start_node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node == end_node)
			return true;
		len = v[node].size();
		for (int i = 0; i < len; i++) {
			new_node = v[node][i].first;
			limit = v[node][i].second;
			if (visited[new_node]) continue;
			if (limit < bound) continue;
			visited[new_node] = 1;
			q.push(new_node);
		}
	}
	return false;
}

int main() {
	int A, B, C;
	int min_weight = 1000000001, max_weight = 0;
	int weight = 1;
	int left, right, mid;
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		if (C < min_weight)
			min_weight = C;
		if (C > max_weight)
			max_weight = C;
		v[A].push_back(make_pair(B, C));
		v[B].push_back(make_pair(A, C));
	}
	cin >> start_node >> end_node;

	left = min_weight;
	right = max_weight;

	while (right - left >= 0) {
		mid = (left + right) / 2;
		if (BFS(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans;

	return 0;
}