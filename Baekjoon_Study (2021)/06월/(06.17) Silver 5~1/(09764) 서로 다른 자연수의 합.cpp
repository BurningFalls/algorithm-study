#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 100999

int dp[2001][2001] = { 0, };
int sum[2001][2001] = { 0, };

int main() {
	FASTIO;
	dp[0][0] = 1;
	FOR(i, 0, 2000)
		sum[0][i] = 1;
	FOR(i, 1, 2000) {
		int SUM = 0;
		FOR(j, 1, i) {
			dp[i][j] = sum[i - j][j - 1];
			SUM = (SUM + dp[i][j]) % MOD;
			sum[i][j] = SUM;
		}
		FOR(j, i + 1, 2000)
			sum[i][j] = SUM;
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << sum[N][N] << "\n";
	}


	return 0;
}