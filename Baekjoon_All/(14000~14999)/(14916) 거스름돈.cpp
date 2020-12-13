#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[100001];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	FOR(i, 1, 50000) {
		dp[i * 2] = i;
	}
	FOR(i, 5, 100000) {
		if (dp[i - 5] == -1) continue;
		if (dp[i] == -1)
			dp[i] = dp[i - 5] + 1;
		else
			dp[i] = min(dp[i], dp[i - 5] + 1);
	}
	int N;
	cin >> N;
	cout << dp[N];

	return 0;
}