#include <iostream>
using namespace std;

int main() {
	int N, K;
	int cnt = 0;
	int arr[11];
	int j;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] > K) continue;
		j = 1;
		while (j * arr[i] <= K) {
			j++;
		}
		j--;
		cnt += j;
		K -= j * arr[i];
	}
	cout << cnt;

	return 0;
}