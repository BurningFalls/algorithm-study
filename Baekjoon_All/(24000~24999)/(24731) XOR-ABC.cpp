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
#define MOD 1000003

ll POW(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll ans = POW(a, b / 2);
	ans = (ans * ans) % MOD;
	if (b % 2 == 1) {
		ans = (ans * a) % MOD;
	}
	return ans;
}

int main() {
	FASTIO;
	ll K;
	cin >> K;
	ll tmp = POW(2, K);
	ll t1 = (tmp + MOD - 1) % MOD;
	ll t2 = (tmp + MOD - 2) % MOD;
	ll t3 = POW(6, MOD - 2);
	cout << (((t1 * t2) % MOD) * t3) % MOD;
	    
	return 0;
}