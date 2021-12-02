#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		ll H;
		cin >> N >> H;
		vector<ll> A(N);
		vector<ll> diff;
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}
		if (N == 1) {
			cout << H << "\n";
			continue;
		}
		FOR(i, 0, N - 2) {
			diff.push_back(A[i + 1] - A[i]);
		}
		sort(ALL(diff));
		vector<ll> sum(LEN(diff), 0);
		sum[0] = diff[0];
		FOR(i, 1, LEN(diff) - 1) {
			sum[i] = sum[i - 1] + diff[i];
		}
		ll left = 1, right = LINF;
		ll ans = 0;
		while (left <= right) {
			ll mid = (left + right) / 2;
			int lb = lower_bound(ALL(diff), mid) - diff.begin();
			ll tmp = mid * (N - lb);
			if (lb != 0) {
				tmp += sum[lb - 1];
			}
			if (tmp >= H) {
				ans = mid;
				right = mid - 1;
			}
			else if (tmp < H) {
				left = mid + 1;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}