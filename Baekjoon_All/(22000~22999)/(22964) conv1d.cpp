#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 998244353

ll DAC(ll x, ll n) {
	if (n == 0)
		return 1;
	ll tmp = DAC(x, n / 2);
	tmp = (tmp * tmp) % MOD;
	if (n % 2 == 1)
		tmp = (tmp * x) % MOD;
	return tmp;
}

int main() {
	FASTIO;
	ll N, K, X;
	cin >> N >> K >> X;
	ll ans = DAC(X, N + K - 2);
	ll tmp = DAC(X * (X + 1) / 2, 2);
	ans = (ans * tmp) % MOD;
	ans = (ans * K) % MOD;
	FOR(i, 1, N - K + 1)
		cout << ans << " ";

	return 0;
}