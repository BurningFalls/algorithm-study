#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> v(N);
	vector<ll> sum(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
		if (i == 0) sum[0] = v[0];
		else sum[i] = sum[i - 1] + v[i];
	}

	ll cnt = 0;
	FOR(i, 0, N - 3) {
		ll t1 = sum[i];
		int left = i + 1, right = N - 2;
		ll ans1 = N - 1;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll t2 = sum[mid] - sum[i];
			ll t3 = sum[N - 1] - sum[mid];
			if (t2 > t3) {
				ans1 = min(ans1, mid);
				right = mid - 1;
			}
			else if (t2 <= t3) {
				left = mid + 1;
			}
		}
		left = i + 1, right = N - 2;
		ll ans2 = 0;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll t3 = sum[N - 1] - sum[mid];
			if (t3 > t1) {
				ans2 = max(ans2, mid);
				left = mid + 1;
			}
			else if (t3 <= t1) {
				right = mid - 1;
			}
		}
		cnt += max(0LL, (ans2 - ans1 + 1));
	}
	cout << cnt;

	return 0;
}