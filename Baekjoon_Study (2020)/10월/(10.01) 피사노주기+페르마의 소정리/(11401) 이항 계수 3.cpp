#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

ll arr[4000001];

ll DQ(ll a, ll b) {
	if (b == 0)
		return 1;
	ll temp = DQ(a, b / 2);
	temp = (temp * temp) % MOD;
	if (b % 2 == 0)
		return temp;
	else if (b % 2 == 1)
		return (temp * a) % MOD;
}

int main() {
	FASTIO;
	ll N, K;
	ll ans = 1;
	ll temp;

	cin >> N >> K;
	arr[0] = 1;
	FOR(i, 1, N)
		arr[i] = (arr[i - 1] * i) % MOD;

	ans *= arr[N];
	temp = (arr[K] * arr[N - K]) % MOD;

	ll x = DQ(temp, MOD - 2);
	ans = (ans * x) % MOD;
	cout << ans;

	return 0;
}