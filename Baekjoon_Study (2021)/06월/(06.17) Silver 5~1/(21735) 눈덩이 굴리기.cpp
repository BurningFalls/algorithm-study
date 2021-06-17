#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];
int dp[101][11];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[0][0] = 1;
	dp[1][1] = 1 + arr[1];
	FOR(i, 2, N) {
		FOR(j, 1, i) {
			if (dp[i - 1][j - 1] == -1 && dp[i - 2][j - 1] == -1)
				continue;
			else if (dp[i - 1][j - 1] == -1)
				dp[i][j] = dp[i - 2][j - 1] / 2 + arr[i];
			else if (dp[i - 2][j - 1] == -1)
				dp[i][j] = dp[i - 1][j - 1] + arr[i];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 2][j - 1] / 2) + arr[i];
		}
	}
	int maxi = 1;
	FOR(i, 0, N) {
		FOR(j, 0, M) {
			cout << dp[i][j] << " ";
			maxi = max(maxi, dp[i][j]);
		}
		cout << "\n";
	}
	cout << maxi;


	return 0;
}