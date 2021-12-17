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

int main() {
	FASTIO;
	ll N;
	cin >> N;
	ll ans = 0;
	FOR(i, 2, N) {
		ll n = i;
		ll sqrtn = sqrt(n);
		ll sub_ans = 1;
		FOR(j, 2, sqrtn) {
			ll tmp = 1;
			while (n % j == 0) {
				tmp *= j;
				n /= j;
			}
			sub_ans *= (tmp - tmp / j);
		}
		if (n > 1) {
			sub_ans *= (n - 1);
		}
		ans += sub_ans;
	}
	cout << ans;

	return 0;
}