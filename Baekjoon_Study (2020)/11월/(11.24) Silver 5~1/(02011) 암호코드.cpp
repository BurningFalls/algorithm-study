#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000

int dp[5001] = { 0, };

int main() {
	FASTIO;
	string s;
	int len;
	cin >> s;
	len = s.size();
	dp[0] = 1;
	if (s[0] != '0')
		dp[1] = 1;
	FOR(i, 1, len - 1) {
		int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (tmp >= 10 && tmp <= 26)
			dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
		if (s[i] != '0')
			dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
	}
	cout << dp[len];

	return 0;
}