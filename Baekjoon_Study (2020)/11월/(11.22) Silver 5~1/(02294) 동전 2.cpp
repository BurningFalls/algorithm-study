#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];
int dp[10001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[0] = 0;
	FOR(i, 1, K)
		dp[i] = 100001;
	FOR(i, 1, N) {
		FOR(j, arr[i], K) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[K] == 100001)
		cout << -1;
	else
		cout << dp[K];

	return 0;
}