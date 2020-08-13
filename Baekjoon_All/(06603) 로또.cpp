#include <iostream>
using namespace std;

int K;
int arr[14] = { 0, };
int answer[6];
bool visited[14] = { 0, };

void DFS(int node, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << answer[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = node; i < K; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		answer[cnt] = arr[i];
		DFS(i + 1, cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	while (true) {
		cin >> K;
		if (K == 0)
			break;

		for (int i = 0; i < K; i++)
			cin >> arr[i];

		DFS(0, 0);

		for (int i = 0; i < K; i++) {
			arr[i] = 0;
			visited[i] = 0;
		}
		cout << endl;
	}

	return 0;
}