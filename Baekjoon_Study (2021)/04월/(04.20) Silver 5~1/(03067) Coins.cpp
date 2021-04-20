#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int coins[21];
int dp[10001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		int N, M;
		cin >> N;
		FOR(i, 1, N)
			cin >> coins[i];
		cin >> M;
		dp[0] = 1;
		FOR(i, 1, N) {
			FOR(j, 0, M - coins[i]) {
				if (dp[j] == 0) continue;
				dp[j + coins[i]] += dp[j];
			}
		}
		cout << dp[M] << "\n";
	}

	return 0;
}