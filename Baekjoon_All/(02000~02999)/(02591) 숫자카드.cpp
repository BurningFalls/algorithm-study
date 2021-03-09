#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int dp[41] = { 0, };

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	dp[0] = 1;
	if (len >= 2) {
		if (s[1] != '0')
			dp[1] += 1;
		int tmp = (s[0] - '0') * 10 + (s[1] - '0');
		if (10 <= tmp && tmp <= 34)
			dp[1] += 1;
	}
	FOR(i, 2, len - 1) {
		if (s[i] != '0')
			dp[i] += dp[i - 1];
		int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= tmp && tmp <= 34)
			dp[i] += dp[i - 2];
	}
	cout << dp[len - 1];

	return 0;
}