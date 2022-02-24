#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
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
	ll N, M;
	cin >> N >> M;
	ll sqrtn = sqrt(N);
	ll sum = 0;
	FOR(i, 1, sqrtn - 1) {
		sum = (sum + int(N / i) * (i % M)) % MOD;
	}
	ll left = sqrtn - 1, right = sqrtn - 1;
	ROF(i, sqrtn, 1) {
		left = right + 1;
		right = N / i;
		ll cnt = right - left + 1;
		ll start = left % M;
		ll tmp1 = (int((start + cnt) / M) * (((M - 1) * M / 2) % MOD)) % MOD;
		ll tmp2 = (start + cnt) % M;
		tmp2 = ((tmp2 - 1) * tmp2 / 2) % MOD;
		ll tmp3 = ((start - 1) * start / 2) % MOD;
		ll ans = (tmp1 + tmp2 - tmp3 + MOD) % MOD;
		sum = (sum + (i * ans) % MOD) % MOD;
	}
	cout << sum;


	return 0;
}