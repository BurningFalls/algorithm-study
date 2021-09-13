#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[100001];
int dp[100001][3];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[1][0] = 0;
	dp[1][1] = arr[1];
	dp[1][2] = arr[1];
	dp[2][0] = arr[1];
	dp[2][1] = arr[2];
	dp[2][2] = dp[1][1] + arr[1] / 2;
	FOR(i, 2, N) {
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i] / 2;
	}
	cout << max({ dp[N][0], dp[N][1], dp[N][2] });

	return 0;
}