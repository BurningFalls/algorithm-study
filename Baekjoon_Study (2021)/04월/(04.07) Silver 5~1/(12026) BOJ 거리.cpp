#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

char arr[1001];
int dp[1001];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[1] = 0;
	FOR(i, 2, N) {
		int mini = INF;
		if (arr[i] == 'B') {
			FOR(j, 1, i - 1) {
				if (arr[j] == 'J' && dp[j] != -1) {
					mini = min(mini, dp[j] + (i - j) * (i - j));
				}
			}
			if (mini != INF)
				dp[i] = mini;
		}
		else if (arr[i] == 'O') {
			FOR(j, 1, i - 1) {
				if (arr[j] == 'B' && dp[j] != -1) {
					mini = min(mini, dp[j] + (i - j) * (i - j));
				}
			}
			if (mini != INF)
				dp[i] = mini;
		}
		else if (arr[i] == 'J') {
			FOR(j, 1, i - 1) {
				if (arr[j] == 'O' && dp[j] != -1) {
					mini = min(mini, dp[j] + (i - j) * (i - j));
				}
			}
			if (mini != INF)
				dp[i] = mini;
		}
	}
	cout << dp[N];

	return 0;
}