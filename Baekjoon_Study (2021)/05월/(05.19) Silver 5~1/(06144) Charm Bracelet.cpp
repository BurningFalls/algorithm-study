#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[3403];
int dp[12881];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	int N, M;
	int W_sum = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		int W, D;
		cin >> W >> D;
		arr[i] = { W, D };
		W_sum += W;
	}
	sort(arr + 1, arr + N + 1);
	int maxi = 0;
	FOR(i, 1, N) {
		ROF(j, M, arr[i].first) {
			if (dp[j - arr[i].first] == -1) continue;
			dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
			maxi = max(maxi, dp[j]);
		}
	}
	cout << maxi;

	return 0;
}