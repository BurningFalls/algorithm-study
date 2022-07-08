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

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

ll Lcm(ll a, ll b) {
	return (a / Gcd(a, b)) * b;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	ll ans = 1;
	FOR(i, 0, N - 3) {
		ll num;
		cin >> num;
		ans = Lcm(ans, num);
	}

	cout << ans;

	return 0;
}