#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[501];
int ans[501];
bool use[501];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		FOR(i, 1, 500) {
			arr[i] = i;
			use[i] = 0;
			ans[i] = 0;
		}
		int N, L, R, S;
		cin >> N >> L >> R >> S;
		int len = R - L + 1;
		int mini = len * (len + 1) / 2;
		int maxi = N * (N + 1) / 2 - (N - len) * (N - len + 1) / 2;
		if (S < mini || maxi < S) {
			cout << "-1\n";
			continue;
		}
		S -= mini;
		FOR(i, 1, len)
			arr[i] += S / len;
		int tmp = S % len;
		ROF(i, len, len - tmp + 1) {
			arr[i] += 1;
		}
		FOR(i, L, R) {
			ans[i] = arr[i - L + 1];
			use[arr[i - L + 1]] = 1;
		}
		int idx = 1;
		while (use[idx] == 1)
			idx++;
		FOR(i, 1, N) {
			if (ans[i] != 0) continue;
			ans[i] = idx;
			idx++;
			while (use[idx] == 1)
				idx++;
		}
		FOR(i, 1, N)
			cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}