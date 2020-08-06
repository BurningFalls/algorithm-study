#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	int arr[101];
	bool visited[101] = { 0, };
	int ans = 0;
	int on_flug = 0;
	bool after[101] = { 0, };
	int left_cnt = 0;
	int sub_node = 0;
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= K; i++) {
		if (visited[arr[i]]) continue;
		if (on_flug == N) {
			left_cnt = 0;
			for (int k = 1; k <= K; k++) {
				after[k] = visited[k];
				if (visited[k] == 1) {
					left_cnt++;
				}
			}
			for (int k = i + 1; k <= K; k++) {
				if (left_cnt == 1) {
					break;
				}
				if (after[arr[k]] == 1) {
					after[arr[k]] = 0;
					left_cnt--;
				}
			}
			for (int k = 1; k <= K; k++) {
				if (after[k] == 1) {
					sub_node = k;
					break;
				}
			}
			visited[sub_node] = 0;
			ans++;
			visited[arr[i]] = 1;
		}
		else {
			visited[arr[i]] = 1;
			on_flug++;
		}
	}
	cout << ans;

	return 0;
}