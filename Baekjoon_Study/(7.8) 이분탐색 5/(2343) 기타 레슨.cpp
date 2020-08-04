#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2000000000

int arr[100001];

int main() {
	int N, M;
	int sum = 0;
	int left, right, mid;
	int temp_sum;
	int cnt;
	int ans = INF;
	bool flag;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	left = sum / M;
	right = sum;
	while (right - left >= 0) {
		flag = true;
		temp_sum = 0;
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				flag = false;
				continue;
			}
			if (temp_sum + arr[i] > mid) {
				cnt++;
				temp_sum = arr[i];
			}
			else
				temp_sum += arr[i];
		}
		if (temp_sum <= mid)
			cnt++;
		else
			flag = false;
		if (!flag)
			left = mid + 1;
		else {
			if (cnt <= M) {
				right = mid - 1;
				ans = min(ans, mid);
			}
			else if (cnt > M)
				left = mid + 1;
		}
	}
	cout << ans;

	return 0;
}