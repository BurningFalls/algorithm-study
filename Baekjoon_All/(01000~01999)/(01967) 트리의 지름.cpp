#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[10001];
bool visited[10001] = { 0, };
int max_weight = -1;
int sum = 0;
int max_node = -1;

void Find(int node) {
	int new_node;
	int weight;
	int len = v[node].size();
	bool flag = false;
	for (int i = 0; i < len; i++) {
		new_node = v[node][i].first;
		if (visited[new_node]) continue;
		flag = true;
		visited[new_node] = 1;
		weight = v[node][i].second;
		sum += weight;
		Find(new_node);
		sum -= weight;
	}
	if (!flag) {
		if (max_weight < sum) {
			max_weight = sum;
			max_node = node;
		}
	}
}

int main() {
	int N;
	int a, b, c;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	visited[1] = 1;
	Find(1);
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	visited[max_node] = 1;
	Find(max_node);

	cout << max_weight;

	return 0;
}