#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[50];

int main() {
	FASTIO;
	dp[1] = 1;
	dp[2] = 2;
	FOR(i, 3, 43)
		dp[i] = dp[i - 1] + dp[i - 2] + 1;
	int T;
	cin >> T;
	while (T--) {
		int V;
		cin >> V;
		int pos = upper_bound(dp + 1, dp + 44, V) - dp;
		cout << pos - 1 << "\n";
	}


	return 0;
}