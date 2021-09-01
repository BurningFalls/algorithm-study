#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

ll arr[300001];

ll Exp(ll x, int n) {
	if (n == 0)
		return 1;
	ll tmp = Exp(x, n / 2);
	ll ans = (tmp * tmp) % MOD;
	if (n % 2 == 1)
		ans = (ans * x) % MOD;
	return ans;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	ll sum = 0;
	FOR(i, 1, N - 1) {
		ll diff = arr[i + 1] - arr[i];
		ll a = Exp(2, N - i) - 1;
		ll b = Exp(2, i) - 1;
		ll ans = (a * b) % MOD;
		ans = (ans * diff) % MOD;
		sum = (sum + ans) % MOD;
	}
	cout << sum;

	return 0;
}