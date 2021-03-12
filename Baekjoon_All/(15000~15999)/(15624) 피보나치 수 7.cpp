#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MOD 1000000007

ll dp[1000001];

int main() {
	FASTIO;
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	FOR(i, 2, n) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[n];

	return 0;
}