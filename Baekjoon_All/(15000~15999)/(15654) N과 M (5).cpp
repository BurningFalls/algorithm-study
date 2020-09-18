#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int ans[9];
bool visited[9] = { 0, };

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		ans[cnt] = arr[i];
		DFS(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	DFS(0);

	return 0;
}