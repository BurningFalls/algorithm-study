#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

void DFS(int node, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = node; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		arr[cnt] = i;
		DFS(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> N >> M;
	DFS(1, 0);

	return 0;
}