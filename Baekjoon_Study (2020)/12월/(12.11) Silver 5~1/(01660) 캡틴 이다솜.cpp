#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[121];
int sum[121];
int dp[300001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	arr[1] = 1;
	sum[1] = 1;
	FOR(i, 2, 120)
		arr[i] = arr[i - 1] + i;
	FOR(i, 2, 120)
		sum[i] = sum[i - 1] + arr[i];
	dp[0] = 0;
	FOR(i, 1, 300000)
		dp[i] = 300001;
	FOR(i, 1, 120) {
		for (int j = 0; j <= 300000; j++) {
			if (j - sum[i] < 0) continue;
			if (dp[j - sum[i]] == 300001) continue;
			dp[j] = min(dp[j], dp[j - sum[i]] + 1);
		}
	}
	cout << dp[N];

	return 0;
}