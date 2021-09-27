#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int W[101], V[101];
int dp[100001];

int main() {
	FASTIO;
	MEMSET(dp, -1);
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> W[i] >> V[i];
	}
	dp[0] = 0;
	FOR(i, 1, N) {
		ROF(j, K, W[i]) {
			if (dp[j - W[i]] == -1) continue;
			dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
		}
	}
	int maxi = 0;
	FOR(i, 0, K)
		maxi = max(maxi, dp[i]);
	cout << maxi;


	return 0;
}