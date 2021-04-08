#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll N;
	ll ans = 0;
	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	ans += N * (N + 1) / 2;
	ans += N - N / 2;
	FOR(i, 2, N / 2) {
		ll tmp = N / i;
		ans += tmp * (tmp + 1) / 2;
	}
	cout << ans;

	return 0;
}