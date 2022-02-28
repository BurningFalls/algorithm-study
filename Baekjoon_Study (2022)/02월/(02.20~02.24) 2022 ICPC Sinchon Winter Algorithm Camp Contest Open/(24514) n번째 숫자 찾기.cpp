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
	int T, K;
	cin >> T >> K;
	vector<ll> cnt(44731, 0), cnt_sum(44731, 0);
	ll num = K;
	ll len = 1;
	cnt[1] = 1;
	cnt_sum[1] = 1;
	FOR(i, 2, 44730) {
		if (num == i) {
			len++;
			num *= K;
		}
		cnt[i] = cnt[i - 1] + len;
	}
	FOR(i, 2, 44730) {
		cnt_sum[i] = cnt_sum[i - 1] + cnt[i];
	}

	FOR(t, 1, T) {
		ll N;
		cin >> N;
		int left = 1, right = sqrt(N) + 10;
		int ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (N > cnt_sum[mid]) {
				ans = max(ans, mid);
				left = mid + 1;
			}
			else if (N <= cnt_sum[mid]) {
				right = mid - 1;
			}
		}
		ll pos = N - cnt_sum[ans];
		left = 1, right = ans + 1;
		ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (pos > cnt[mid]) {
				ans = max(ans, mid);
				left = mid + 1;
			}
			else if (pos <= cnt[mid]) {
				right = mid - 1;
			}
		}
		pos = pos - cnt[ans];
		ans += 1;
		vector<int> v;
		while (ans) {
			v.push_back(ans % K);
			ans /= K;
		}
		int len = LEN(v);
		cout << v[len - pos] << "\n";
	}


	return 0;
}