#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[1001];
int dp[1001][1001];

int DP(int cnt, int left, int right) {
	if (cnt == N + 1)
		return 0;
	if (dp[left][right])
		return dp[left][right];
	int temp1 = DP(cnt + 1, left + 1, right);
	int temp2 = DP(cnt + 1, left, right - 1);
	if (cnt % 2 == 1) {
		temp1 += arr[left];
		temp2 += arr[right];
		dp[left][right] = max(temp1, temp2);
	}
	else if (cnt % 2 == 0) {
		dp[left][right] = min(temp1, temp2);
	}
	return dp[left][right];
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		cout << DP(1, 1, N) << "\n";
	}

	return 0;
}