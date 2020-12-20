#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll dp[117];

int main() {
	FASTIO;
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	FOR(i, 4, n)
		dp[i] = dp[i - 1] + dp[i - 3];
	cout << dp[n];

	return 0;
}