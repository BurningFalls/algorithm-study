#include <iostream>
using namespace std;

int N;
int result = 0;
int row[15];

bool promising(int node) {
	for (int i = 0; i < node; i++) {
		if (row[i] == row[node]) return false;
		if (row[i] + i == row[node] + node) return false;
		if (row[i] - i == row[node] - node) return false;
	}
	return true;
}

void DFS(int cnt) {
	if (cnt == N) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) {
		row[cnt] = i;
		if (promising(cnt)) {
			DFS(cnt + 1);
		}
	}
}

int main() {
	cin >> N;
	DFS(0);
	cout << result;

	return 0;
}