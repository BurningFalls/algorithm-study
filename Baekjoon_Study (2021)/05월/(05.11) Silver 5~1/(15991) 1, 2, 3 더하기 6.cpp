#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000009

ll dp[100001] = { 0, };

int main() {
	FASTIO;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	FOR(i, 6, 100000) {
		dp[i] = (dp[i - 2] + dp[i - 4] + dp[i - 6]) % MOD;
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}


	return 0;
}