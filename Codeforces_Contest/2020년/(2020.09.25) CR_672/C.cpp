#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll arr[300001];
ll dp[300001][2];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		FOR(i, 1, n)
			cin >> arr[i];
		if (n == 1)
			cout << arr[1];
		else {
			dp[1][0] = arr[1];
			dp[2][0] = max(dp[1][0], arr[2]);
			dp[2][1] = dp[1][0] - arr[2];
			FOR(i, 3, n) {
				dp[i][0] = max({ dp[i - 1][0], arr[i], dp[i - 1][1] + arr[i] });
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - arr[i]);
			}
			cout << max(dp[n][0], dp[n][1]);
		}
		cout << "\n";
	}

	return 0;
}