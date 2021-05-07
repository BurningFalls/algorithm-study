#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

ll Calc(int x) {
	if (x == 0)
		return 1;
	if (x == 1)
		return 2;
	ll tmp = Calc(x / 2);
	ll n = (tmp * tmp) % MOD;
	if (x % 2 == 0) {
		return n;
	}
	else if (x % 2 == 1) {
		return (n * 2) % MOD;
	}
}

int main() {
	FASTIO;
	ll sum = 0;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		ll C, K;
		cin >> C >> K;
		sum = (sum + (((C * K) % MOD) * Calc(K - 1)) % MOD) % MOD;
	}
	cout << sum;

	return 0;
}