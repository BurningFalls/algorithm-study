#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll dp[66][10];
ll sum[10] = { 0, };

int main() {
	FASTIO;
	FOR(i, 0, 9) {
		dp[1][i] = 1;
		sum[i] = i + 1;
	}
	FOR(i, 2, 65) {
		FOR(j, 0, 9) {
			dp[i][j] = sum[j];
			if (j == 0)
				sum[j] = dp[i][j];
			sum[j] = sum[j - 1] + dp[i][j];
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n + 1][9] << "\n";
	}

	return 0;
}