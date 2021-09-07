#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 998244353

int main() {
	FASTIO;
	ll N;
	cin >> N;
	int sqrtN = sqrt(N);
	ll ans = 0;
	FOR(i, 1, sqrtN) {
		ll tmp = (N / i - i) / 2 + 1;
		ans = (ans + tmp) % MOD;
	}
	cout << ans;

	return 0;
}