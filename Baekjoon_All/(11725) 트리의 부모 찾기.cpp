#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int parent[100001] = { 0, };
bool visited[100001] = { 0, };

void Find(int node) {
	int new_node;
	int len;
	len = v[node].size();
	for (int i = 0; i < len; i++) {
		new_node = v[node][i];
		if (visited[new_node]) continue;
		visited[new_node] = 1;
		parent[new_node] = node;
		Find(new_node);
	}
}

int main() {
	int N;
	int a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visited[1] = 1;
	Find(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}