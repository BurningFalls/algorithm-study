#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool visited[9];

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		arr[cnt] = i;
		DFS(cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;
	DFS(0);

	return 0;
}