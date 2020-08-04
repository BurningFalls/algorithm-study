#include <iostream>
#include <vector>
using namespace std;

int N, M, C;
int clr[200001];
vector<int> v[200001];
vector<int> child[200001];
bool visited[200001] = { 0, };
int cnt = 0;

void Find_Child(int node) {
	int len = v[node].size();
	int new_node;
	for (int i = 0; i < len; i++) {
		new_node = v[node][i];
		if (visited[new_node]) continue;
		visited[new_node] = 1;
		child[node].push_back(new_node);
		Find_Child(new_node);
		visited[new_node] = 0;
	}
}

void DFS(int node, int color) {
	int len = child[node].size();
	int new_node;
	if (clr[node] <= color)
		cnt++;
	for (int i = 0; i < len; i++) {
		new_node = child[node][i];
		DFS(new_node, color);
	}
}

int main() {
	int a, b;
	int vi, ci;
	int sum = 0;
	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) {
		cin >> clr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	visited[1] = 1;
	Find_Child(1);

	for (int i = 0; i < M; i++) {
		cnt = 0;
		cin >> vi >> ci;
		DFS(vi, ci);
		sum = (sum + cnt) % 1000000007;
	}
	cout << sum;

	return 0;
}