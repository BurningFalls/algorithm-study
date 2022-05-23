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
#define INF int(2e9)
#define LINF ll(1e18)

int dp[3001][2][3];

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = LEN(s);
	vector<vector<int>> dp(len, vector<int>(2));
	
	if (s[0] >= 'a' && s[0] <= 'z') {
		dp[0][0] = 1;
		dp[0][1] = 2;
	}
	else if (s[0] >= 'A' && s[0] <= 'Z') {
		dp[0][0] = 2;
		dp[0][1] = 2;
	}
	FOR(i, 1, len - 1) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
			dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
		}
	}

	cout << min(dp[len - 1][0], dp[len - 1][1]);

	return 0;
}