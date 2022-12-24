#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MOD 1000000007

ll multi(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll tmp = multi(a, b / 2);
	tmp = (tmp * tmp) % MOD;
	if (b % 2 == 1) {
		tmp = (tmp * a) % MOD;
	}
	return tmp;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	ll up = 1, down = 1;

	if (M == 1) {
		up = 0, down = 1;
	}
	else if (M > (1LL << N)) {
		up = 1, down = 1;
	}
	else {
		ll t = (1LL << N);
		FOR(i, 1, M - 1) {
			down = (down * t) % MOD;
		}
		FOR(i, t - M + 1, t - 1) {
			up = (up * i) % MOD;
		}
		up = (down - up + MOD) % MOD;
	}

	ll ans = (up * multi(down, MOD - 2)) % MOD;
	cout << ans;

	return 0;
}