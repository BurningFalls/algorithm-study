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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> H(N);
	FOR(i, 0, N - 1) {
		cin >> H[i];
	}
	ll ans = 0;
	FOR(i, 0, N - 2) {
		ll t1 = abs(H[i] - H[i + 1]);
		ll t2 = H[i] + H[i + 1];
		ans += t1 * t1 + t2 * t2;
	}
	cout << ans;

	return 0;
}