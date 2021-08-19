#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 200001
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

bool arr[200001];
int dp[200001][2][2];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		FOR(i, 1, n)
			cin >> arr[i];
		dp[1][0][0] = INF;
		dp[1][0][1] = INF;
		dp[1][1][0] = arr[1];
		dp[1][1][1] = INF;
		FOR(i, 2, n) {
			dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][1][1]);
			dp[i][0][1] = dp[i - 1][0][0];
			dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
			dp[i][1][1] = dp[i - 1][1][0];
			if (arr[i] == 1) {
				dp[i][1][0]++;
				dp[i][1][1]++;
			}
		}
		cout << min({ dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1] }) << "\n";
	}

	return 0;
}