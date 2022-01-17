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
	ll N, K;
	cin >> N >> K;
	ll sum = 0;
	FOR(i, 0, N - 1) {
		ll num;
		cin >> num;
		sum += num;
	}
	ll rest = K - sum;
	ll ans = 1;
	FOR(i, rest + 1, rest + N) {
		ans = (ans * i) % MOD;
	}
	cout << ans;

	return 0;
}