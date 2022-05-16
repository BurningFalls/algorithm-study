#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007

int main() {
	FASTIO;
	ll N;
	cin >> N;
	ll ans1 = 0;
	ll ans2 = 1;

	FOR(i, 1, N) {
		ans1 = (ans1 + ((i * i) % MOD * (i + 1)) % MOD) % MOD;
	}

	FOR(i, 2, N) {
		ans2 = (((ans2 * i) % MOD) * i) % MOD;
	}

	cout << ans1 << " " << ans2;

	return 0;
}