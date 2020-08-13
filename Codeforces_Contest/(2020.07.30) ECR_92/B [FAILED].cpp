#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int sub_sum[100001];
int sum[100001];

int main() {
	int T;
	int n, k, z;
	int max_sub_sum;
	int idx;
	int temp;
	int ans;
	cin >> T;
	arr[0] = 0;
	sum[0] = 0;
	for (int t = 0; t < T; t++) {
		ans = 0;
		max_sub_sum = 0;
		cin >> n >> k >> z;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (i <= k + 1) {
				sub_sum[i] = arr[i] + arr[i - 1];
				if (max_sub_sum < sub_sum[i]) {
					max_sub_sum = sub_sum[i];
					idx = i;
				}
				sum[i] = sum[i - 1] + arr[i];
			}
		}
		if (k + 1 <= idx || z == 0) {
			cout << sum[k + 1] << "\n";
		}
		else {
			temp = k - (idx - 2);
			ans = sum[idx - 1];
			if (temp % 2 == 0) {
				if (temp / 2 <= z) {
					ans += sub_sum[idx] * (temp / 2);
				}
				else if (temp / 2 > z) {
					ans += sub_sum[idx] * z;
					temp -= z * 2;
					ans += (sum[idx - 1 + temp] - sum[idx - 1]);
				}
			}
			else if (temp % 2 == 1) {
				if (temp / 2 <= z) {
					ans += sub_sum[idx] * (temp / 2);
					ans += arr[idx];
				}
				else if (temp / 2 > z) {
					ans += sub_sum[idx] * z;
					temp -= z * 2;
					ans += (sum[idx + temp] - sum[idx - 1]);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}