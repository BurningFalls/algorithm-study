#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

ll Squaring(ll x, ll n) {
	if (n == 1)
		return x;
	ll tmp = Squaring(x, n / 2);
	tmp = (tmp * tmp) % MOD;
	if (n % 2 == 1)
		tmp = (tmp * x) % MOD;
	return tmp;
}

int main() {
	FASTIO;
	int M;
	cin >> M;
	ll sum = 0;
	FOR(i, 1, M) {
		int N, S;
		cin >> N >> S;
		ll squared = Squaring(N, MOD - 2);
		ll tmp = (S * squared) % MOD;
		sum = (sum + tmp) % MOD;
	}
	cout << sum;

	return 0;
}