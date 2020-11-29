#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000009

ll dp[1000001];

int main() {
	FASTIO;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	FOR(i, 4, 1000000)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}