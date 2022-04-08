#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

ll dp[11][101][101][101];
ll fact[11];

ll DP(int n, int r, int g, int b) {
	if (n == 0) {
		return 1;
	}
	ll& ret = dp[n][r][g][b];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	if (r >= n)
		ret += DP(n - 1, r - n, g, b);
	if (g >= n)
		ret += DP(n - 1, r, g - n, b);
	if (b >= n)
		ret += DP(n - 1, r, g, b - n);
	if (n % 2 == 0) {
		ll tmp = fact[n] / (fact[n / 2] * fact[n / 2]);
		if (r >= n / 2 && g >= n / 2)
			ret += DP(n - 1, r - n / 2, g - n / 2, b) * tmp;
		if (r >= n / 2 && b >= n / 2)
			ret += DP(n - 1, r - n / 2, g, b - n / 2) * tmp;
		if (g >= n / 2 && b >= n / 2)
			ret += DP(n - 1, r, g - n / 2, b - n / 2) * tmp;
	}
	if (n % 3 == 0) {
		ll tmp = fact[n] / (fact[n / 3] * fact[n / 3] * fact[n / 3]);
		if (r >= n / 3 && g >= n / 3 && b >= n / 3)
			ret += DP(n - 1, r - n / 3, g - n / 3, b - n / 3) * tmp;
	}
	return ret;
}

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	fact[0] = 1;
	FOR(i, 1, 10) {
		fact[i] = fact[i - 1] * i;
	}
	int N, R, G, B;
	cin >> N >> R >> G >> B;
	
	cout << DP(N, R, G, B);

	return 0;
}