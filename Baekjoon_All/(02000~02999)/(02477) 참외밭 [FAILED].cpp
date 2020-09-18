#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int K;
	int arr[6][2];
	bool visited[5] = { 0, };
	int node;
	int small_rec, big_rec;
	int max_row = 0, max_col = 0;
	cin >> K;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 6; i++) {
		if (arr[i][0] == 3 || arr[i][0] == 4) {
			max_col = max(max_col, arr[i][1]);
		}
		else if (arr[i][0] == 1 || arr[i][0] == 2) {
			max_row = max(max_row, arr[i][1]);
		}
		if (visited[arr[i][0]]) {
			node = i - 1;
			break;
		}
		else
			visited[arr[i][0]] = 1;
	}
	small_rec = arr[node][1] * arr[node + 1][1];
	big_rec = max_col * max_row;
	cout << (big_rec - small_rec) * K;

	return 0;
}