#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int dp[100001][2];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N - 1)
		cin >> arr[i];
	dp[1][0] = 1;
	dp[1][1] = 1;
	int maxi = 0;
	FOR(i, 2, N) {
		if (arr[i - 1] <= K) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}
		else {
			dp[i][0] = 1;
			dp[i][1] = dp[i - 1][0] + 1;
		}
		maxi = max(maxi, dp[i][0]);
		maxi = max(maxi, dp[i][1]);
	}
	cout << maxi;

	return 0;
}