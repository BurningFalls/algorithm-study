#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	int left, right, mid;
	int cnt;
	int ans;
	cin >> N >> K;

	left = 1;
	right = K;
	while (right - left >= 0) {
		mid = (left + right) / 2;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < K)
			left = mid + 1;
		else if (cnt >= K) {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}