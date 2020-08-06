#include <iostream>
using namespace std;

int N;
int edge[101][101] = { 0, };
int road[101][101] = { 0, };
int visited[101] = { 0, };

void dfs(int start, int node) {
	for (int i = 0; i < N; i++) {
		if (edge[node][i] == 1 && !visited[i]) {
			visited[i] = 1;
			road[node][i] = 1;
			road[start][i] = 1;
			dfs(start, i);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> edge[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		dfs(i, i);
		for (int j = 0; j < N; j++) {
			visited[j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << road[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}