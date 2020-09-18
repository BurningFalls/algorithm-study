#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[100000][3];
int dp[2][3];

int main() {
	FASTIO;
	int N;
	int ans1, ans2;
	cin >> N;
	FOR(i, 0, N - 1) {
		FOR(j, 0, 2) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	FOR(i, 1, N - 1) {
		int temp = !(i % 2);
		dp[i % 2][0] = max(dp[temp][0], dp[temp][1]) + arr[i][0];
		dp[i % 2][1] = max({ dp[temp][0], dp[temp][1], dp[temp][2] }) + arr[i][1];
		dp[i % 2][2] = max(dp[temp][1], dp[temp][2]) + arr[i][2];
	}
	if ((N - 1) % 2 == 0)
		ans1 = max({ dp[0][0], dp[0][1], dp[0][2] });
	else
		ans1 = max({ dp[1][0], dp[1][1], dp[1][2] });
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	FOR(i, 1, N - 1) {
		int temp = !(i % 2);
		dp[i % 2][0] = min(dp[temp][0], dp[temp][1]) + arr[i][0];
		dp[i % 2][1] = min({ dp[temp][0], dp[temp][1], dp[temp][2] }) + arr[i][1];
		dp[i % 2][2] = min(dp[temp][1], dp[temp][2]) + arr[i][2];
	}
	if ((N - 1) % 2 == 0)
		ans2 = min({ dp[0][0], dp[0][1], dp[0][2] });
	else
		ans2 = min({ dp[1][0], dp[1][1], dp[1][2] });

	cout << ans1 << " " << ans2;

	return 0;
}