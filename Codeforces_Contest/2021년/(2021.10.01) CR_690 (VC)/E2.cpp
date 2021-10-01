#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())
#define MOD 1000000007

int arr[200001];
ll fact[200001];

ll POW(ll x, int n) {
	if (n == 0)
		return 1;
	ll ans = POW(x, n / 2);
	ans = (ans * ans) % MOD;
	if (n % 2 == 1)
		ans = (ans * x) % MOD;
	return ans;
}

int main() {
	FASTIO;
	fact[0] = 1;
	FOR(i, 1, 200000)
		fact[i] = (fact[i - 1] * i) % MOD;
	int T;
	cin >> T;
	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		sort(arr + 1, arr + N + 1);
		ll ans = 0;
		FOR(i, 1, N) {
			int ub = upper_bound(arr + 1, arr + N + 1, arr[i] + K) - arr;
			ll cnt = (ll)ub - 1 - i;
			if (cnt < M - 1) continue;
			ll tmp = (fact[cnt] * POW((fact[M - 1] * fact[cnt - M + 1]) % MOD, MOD - 2)) % MOD;
			ans = (ans + tmp) % MOD;
		}
		cout << ans << "\n";
	}

	return 0;
}