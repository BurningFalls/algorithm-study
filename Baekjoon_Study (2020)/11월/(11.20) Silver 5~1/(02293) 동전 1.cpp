#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
int arr[101];
int dp[10001] = { 0, };

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	dp[0] = 1;
	FOR(i, 1, N) {
		FOR(j, 1, K) {
			if (j - arr[i] < 0) continue;
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[K];

	return 0;
}