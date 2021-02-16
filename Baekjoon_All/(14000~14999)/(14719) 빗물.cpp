#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)

int H, W;
int arr[502];
int left_max[502], right_max[502];

int main() {
	FASTIO;
	int ans = 0;
	cin >> H >> W;
	FOR(i, 1, W) {
		cin >> arr[i];
	}
	left_max[0] = 0;
	left_max[W + 1] = 0;
	FOR(i, 1, W) {
		left_max[i] = max(left_max[i - 1], arr[i]);
	}
	right_max[0] = 0;
	right_max[W + 1] = 0;
	ROF(i, W, 1) {
		right_max[i] = max(right_max[i + 1], arr[i]);
	}
	int left, right;
	FOR(i, 1, W) {
		int temp = min(left_max[i - 1], right_max[i + 1]);
		if (temp > arr[i]) {
			ans += temp - arr[i];
		}
	}
	cout << ans;

	return 0;
}