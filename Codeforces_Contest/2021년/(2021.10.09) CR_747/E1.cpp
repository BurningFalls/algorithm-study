#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long int ll;
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define MOD 1000000007

ll POW(ll x, ll n) {
	if (n == 0)
		return 1;
	ll ans = POW(x, n / 2);
	ans = (ans * ans) % MOD;
	if (n % 2 == 1)
		ans = (ans * x) % MOD;
	return ans;
}

int main() {
	FASTIO;
	ll K;
	cin >> K;
	ll tmp = ll(pow(2, K)) - 2;
	ll ans = POW(4, tmp);
	ans = (ans * 6) % MOD;
	P1(ans);

	return 0;
}