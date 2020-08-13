#include <bits/stdc++.h>
using namespace std;

int cnt[100001] = { 0, };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	int max_cnt;
	int sam;
	int num;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		memset(cnt, 0, sizeof(cnt));
		max_cnt = 0;
		sam = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			cnt[num] += 1;
			max_cnt = max(max_cnt, cnt[num]);
		}
		for (int i = 1; i <= 100000; i++) {
			if (cnt[i] == max_cnt)
				sam++;
		}
		cout << (n - sam) / (max_cnt - 1) - 1 << "\n";
	}

	return 0;
}