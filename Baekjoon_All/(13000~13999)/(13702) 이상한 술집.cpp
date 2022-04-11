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
	int N, K;
	cin >> N >> K;
	vector<ll> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	ll left = 0, right = (1LL << 31) - 1;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int cnt = 0;
		FOR(i, 0, N - 1) {
			cnt += v[i] / mid;
		}
		if (cnt >= K) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else if (cnt < K) {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}