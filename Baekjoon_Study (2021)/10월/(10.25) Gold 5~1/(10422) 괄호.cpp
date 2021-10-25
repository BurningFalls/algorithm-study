#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define MOD 1000000007

int dp[5001][5001];

int main() {
	FASTIO;
	FOR(i, 1, 5000) {
		dp[i][i] = 1;
		ROF(j, i - 1, (i + 1) / 2) {
			dp[i][j] = dp[i - 1][j - 1];
			if (i / 2 - 1 >= i - 1 - j) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int L;
		cin >> L;
		cout << (L % 2 == 0 ? dp[L][L / 2] : 0) << "\n";
	}


	return 0;
}