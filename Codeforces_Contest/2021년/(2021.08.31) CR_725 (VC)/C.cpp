#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, L, R;
		cin >> N >> L >> R;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		sort(arr + 1, arr + N + 1);
		ll ans = 0;
		FOR(i, 1, N) {
			int lb = lower_bound(arr + i + 1, arr + N + 1, L - arr[i]) - arr;
			int ub = upper_bound(arr + i + 1, arr + N + 1, R - arr[i]) - arr;
			ans += ((ll)ub - lb);
		}
		cout << ans << "\n";
	}

	return 0;
}