#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

ll Fact[4000001];

ll Exp(ll x, int n) {
	if (n == 0)
		return 1;
	ll tmp = Exp(x, n / 2);
	ll ans = (tmp * tmp) % MOD;
	if (n % 2 == 1)
		ans = (ans * x) % MOD;
	return ans;
}

int main() {
	FASTIO;
	Fact[0] = 1;
	FOR(i, 1, 4000000)
		Fact[i] = (Fact[i - 1] * i) % MOD;
	int M;
	cin >> M;
	FOR(m, 1, M) {
		ll N, K;
		cin >> N >> K;
		ll A = Fact[N];
		ll B = (Fact[K] * Fact[N - K]) % MOD;
		ll ans = (A * Exp(B, MOD - 2)) % MOD;
		cout << ans << "\n";
	}


	return 0;
}