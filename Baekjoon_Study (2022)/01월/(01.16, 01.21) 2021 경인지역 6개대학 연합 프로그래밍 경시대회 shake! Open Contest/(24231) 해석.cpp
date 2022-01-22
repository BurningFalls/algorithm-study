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
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007

int main() {
	FASTIO;
	string S;
	cin >> S;
	int len = LEN(S);
	vector<vector<ll>> dp(len + 1, vector<ll>(len + 1, 0));
	FOR(i, 1, len) {
		dp[i][i - 1] = 1;
	}
	FOR(i, 2, len) {
		FOR(left, 0, len - i) {
			int right = left + i - 1;
			FOR(j, left + 1, right) {
				if (S[left] == S[j]) continue;
				dp[left][right] = (dp[left][right] + dp[left + 1][j - 1] * dp[j + 1][right]) % MOD;
			}
		}
	}
	cout << dp[0][len - 1];

	return 0;
}