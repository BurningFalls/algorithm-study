#include <iostream>
#include <vector>
using namespace std;

vector<int> v[500001];
int visited[500001] = { 0, };
int ans = 0;

void DFS(int node) {
	int len = v[node].size();
	int new_node;
	bool flag = false;
	for (int i = 0; i < len; i++) {
		new_node = v[node][i];
		if (visited[new_node]) continue;
		flag = true;
		visited[new_node] = visited[node] + 1;
		DFS(new_node);
		visited[new_node] = 0;
	}
	if (!flag) {
		ans += visited[node] - 1;
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
	DFS(1);

	if (ans % 2 == 0)
		cout << "No";
	else if (ans % 2 == 1)
		cout << "Yes";

	return 0;
}