#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	int* arr = new int[N + 1];
	int* visited = new int[N + 1];
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			for (int j = i + 1; j <= N; j++) {
				if (!visited[j]) {
					if (arr[i] + arr[j] == M) {
						ans++;
						visited[j] = 1;
					}
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}