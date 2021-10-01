#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		sort(arr + 1, arr + N + 1);
		ll ans = 0;
		FOR(i, 1, N) {
			int ub = upper_bound(arr + 1, arr + N + 1, arr[i] + 2) - arr;
			ll cnt = ub - 1 - i;
			if (cnt < 2) continue;
			ans += cnt * (cnt - 1) / 2;
		}
		cout << ans << "\n";
	}

	return 0;
}