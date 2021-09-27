#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int K[101];
int S[101];
int dp[10001];

int main() {
	FASTIO;
	MEMSET(dp, -1);
	int N, T;
	cin >> N >> T;
	FOR(i, 1, N) {
		cin >> K[i] >> S[i];
	}
	dp[0] = 0;
	FOR(i, 1, N) {
		ROF(j, T, K[i]) {
			if (dp[j - K[i]] == -1) continue;
			dp[j] = max(dp[j], dp[j - K[i]] + S[i]);
		}
	}
	int maxi = 0;
	FOR(i, 0, T)
		maxi = max(maxi, dp[i]);
	cout << maxi;


	return 0;
}