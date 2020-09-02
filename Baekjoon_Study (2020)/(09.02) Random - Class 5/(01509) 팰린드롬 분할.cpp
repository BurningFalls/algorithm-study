#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int dp[2501][2501] = { 0, };
int dp2[2501] = { 0, };

int main() {
	FASTIO;
	string s;
	cin >> s;
	FOR(i, 0, s.size() - 1)
		dp[i][i] = 1;
	FOR(len, 2, s.size()) {
		FOR(start, 0, s.size() - len) {
			int end = start + len - 1;
			if (len == 2 && s[start] == s[end])
				dp[start][end] = 1;
			if (len != 2 && dp[start + 1][end - 1] == 1 && s[start] == s[end])
				dp[start][end] = 1;
		}
	}
	FOR(i, 0, s.size() - 1) {
		int temp = 2501;
		FOR(j, 0, i) {
			if (dp[j][i] == 0) continue;
			if (j == 0)
				temp = 0;
			else
				temp = min(temp, dp2[j - 1]);
		}
		dp2[i] = temp + 1;
	}
	cout << dp2[s.size() - 1];

	return 0;
}