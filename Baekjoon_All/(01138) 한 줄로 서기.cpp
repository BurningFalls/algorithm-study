#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[11];
	int ans[11] = { 0, };
	int cnt;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (cnt == arr[i]) {
				for (int k = j; k <= N; k++) {
					if (ans[k] == 0) {
						ans[k] = i;
						j = N;
						break;
					}
				}
			}
			if (ans[j] == 0) {
				cnt++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}