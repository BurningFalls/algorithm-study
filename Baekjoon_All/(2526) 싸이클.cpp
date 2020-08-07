#include <iostream>
using namespace std;

int visited[97] = { 0, };
int N, P;
int answer = 1;

void DFS(int node) {
	int new_node;
	new_node = (node * N) % P;
	if (visited[new_node] != 0) {
		answer = (visited[node] + 1) - visited[new_node];
		return;
	}
	else {
		visited[new_node] = visited[node] + 1;
		DFS(new_node);
	}
}

int main() {
	cin >> N >> P;
	if (N < P) {
		visited[N] = 1;
	}
	DFS(N);
	cout << answer;

	return 0;
}