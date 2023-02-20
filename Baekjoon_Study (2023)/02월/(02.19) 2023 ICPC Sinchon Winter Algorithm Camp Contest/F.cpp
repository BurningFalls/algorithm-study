#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	map<pll, ll> mp;
	FOR(i, 1, N) {
		ll x, y;
		cin >> x >> y;
		ll tmp = 2 * M;
		ll tx = x;
		FOR(i, 0, K - 1) {
			ll gcd = Gcd(tx, y);
			mp[{tx / gcd, y / gcd}]++;
			tx = tmp - tx;
			tmp += 2 * M;
		}
	}

	ll maxi = 0;
	for (const auto &x : mp) {
		maxi = max(maxi, x.second);
	}
	cout << maxi;

	return 0;
}