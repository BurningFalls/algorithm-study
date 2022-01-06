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
	int N;
	ll K;
	cin >> N >> K;
	vector<ll> A(N + 1);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	ll left = 1, right = 1500000000;
	ll ans = LINF;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = mid * (mid + 1) / 2;
		FOR(i, 0, N - 2) {
			ll diff = min(mid, A[i + 1] - A[i]);
			sum += mid * diff - (diff - 1) * diff / 2;
		}
		if (sum >= K) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;

	return 0;
}