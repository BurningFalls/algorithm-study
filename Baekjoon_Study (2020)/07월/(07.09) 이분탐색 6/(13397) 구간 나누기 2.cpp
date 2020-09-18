#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int arr[5001];
	int all_min = 10001, all_max = 0;
	int left, right, mid;
	int cnt;
	int sub_min, sub_max;
	bool flag;
	int ans = 10000;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		all_min = min(all_min, arr[i]);
		all_max = max(all_max, arr[i]);
	}
	left = 0;
	right = all_max - all_min;
	while (right - left >= 0) {
		cnt = 0;
		sub_min = 10001;
		sub_max = 0;
		flag = true;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			sub_min = min(sub_min, arr[i]);
			sub_max = max(sub_max, arr[i]);
			if (sub_max - sub_min > mid) {
				cnt++;
				sub_min = arr[i];
				sub_max = arr[i];
			}
			if (cnt > M - 1) {
				flag = false;
				break;
			}
		}
		cnt++;
		if (cnt > M)
			flag = false;
		if (!flag) {
			left = mid + 1;
		}
		else if (flag) {
			ans = min(ans, mid);
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}