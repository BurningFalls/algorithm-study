#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000007

int dp[10001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	dp[0] = 1;
	FOR(i, 1, N) {
		dp[i] = dp[i - 1];
		if (i - M < 0) continue;
		dp[i] = (dp[i] + dp[i - M]) % MOD;
	}
	cout << dp[N];

	return 0;
}