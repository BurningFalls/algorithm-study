#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int dp[10001][4];

int main() {
	FASTIO;
	dp[1][2] = 0, dp[1][3] = 0;
	dp[2][2] = 1, dp[2][3] = 0;
	dp[3][2] = 1, dp[3][3] = 1;
	FOR(i, 4, 10000) {
		dp[i][2] = 1 + dp[i - 2][2];
		dp[i][3] = 1 + dp[i - 3][2] + dp[i - 3][3];
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << 1 + dp[N][2] + dp[N][3] << "\n";
	}

	return 0;
}