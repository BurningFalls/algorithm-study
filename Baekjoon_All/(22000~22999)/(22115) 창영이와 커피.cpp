#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];
int dp[100001];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int N, K;
	cin >> N >> K;
	int sum = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr + 1, arr + N + 1);
	dp[0] = 0;
	FOR(i, 1, N) {
		ROF(j, sum, arr[i]) {
			if (dp[j - arr[i]] == -1) continue;
			if (dp[j] == -1)
				dp[j] = dp[j - arr[i]] + 1;
			else
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (K > sum)
		cout << -1;
	else
		cout << dp[K];

	return 0;
}