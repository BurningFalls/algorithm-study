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

int Len(int num) {
	int t = 1;
	FOR(i, 1, 8) {
		if (num >= t && num < t * 10) {
			return i;
		}
		t *= 10;
	}
	return 0;
}

int main() {
	FASTIO;
	vector<ll> v(9);
	v[0] = 1;
	FOR(i, 1, 8) {
		v[i] = v[i - 1] * 10;
	}
	ll N, K;
	cin >> N >> K;
	ll ans = 0;
	FOR(i, 1, N) {
		
		ans = ans * v[Len(i)] + i;
		ans = ans % K;
	}
	cout << ans;

	return 0;
}