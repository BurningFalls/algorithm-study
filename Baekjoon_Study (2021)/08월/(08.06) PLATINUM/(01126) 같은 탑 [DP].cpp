#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 500001

int arr[51];
int dp[51][MAX];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int N;
	int sum = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum += arr[i];
	}
	dp[0][0] = 0;
	FOR(i, 1, N) {
		FOR(j, 0, sum) {
			dp[i][j] = dp[i - 1][j];
			if (dp[i - 1][j + arr[i]] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j + arr[i]]);
			if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
			if (arr[i] - j >= 0 && dp[i - 1][arr[i] - j] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][arr[i] - j] + j);
		}
	}
	if (dp[N][0] == 0)
		cout << -1;
	else
		cout << dp[N][0];

	return 0;
}