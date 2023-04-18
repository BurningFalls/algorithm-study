#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MOD 1000000007

int main() {
	FASTIO;
	string s;
	cin >> s;
	vector<ll> v(100001);
	v[0] = 1;
	FOR(i, 1, 100000) {
		v[i] = (v[i - 1] * 2) % MOD;
	}
	ll ans = 0;
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == 'X') continue;
		ans = (ans + v[i]) % MOD;
	}
	cout << ans;

	return 0;
}