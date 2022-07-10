#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MOD 1000000007

ll Pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll ans = Pow(a, b / 2);
	ans = (ans * ans) % MOD;
	if (b % 2 == 1) {
		ans = (ans * a) % MOD;
	}
	return ans;
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<ll> fact(2001);
	fact[0] = 1;
	FOR(i, 1, 2000) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
	}
	ll ans = Pow(2, K - 1);
	ans = (ans * fact[N]) % MOD;
	ll tmp = (fact[N - K] * fact[K]) % MOD;
	tmp = Pow(tmp, MOD - 2);
	ans = (ans * tmp) % MOD;
	cout << ans;

	return 0;
}