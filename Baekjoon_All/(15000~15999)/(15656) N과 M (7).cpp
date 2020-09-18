#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int ans[9];

void DFS(int node, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		ans[cnt] = arr[i];
		DFS(i, cnt + 1);
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
	DFS(0, 0);

	return 0;
}