#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int arr[100001][3];
int dp[100001][3];

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N) {
			FOR(j, 0, 2) {
				cin >> arr[i][j];
			}
		}
		dp[1][0] = INF;
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[1][1] + arr[1][2];
		FOR(i, 2, N) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
			dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] }) + arr[i][1];
			dp[i][2] = min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] }) + arr[i][2];
		}
		cout << idx << ". " << dp[N][1] << "\n";
		idx++;
	}

	return 0;
}