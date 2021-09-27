#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int lose[21];
int win[21];
int dp[101];

int main() {
	FASTIO;
	MEMSET(dp, -1);
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> lose[i];
	FOR(i, 1, N)
		cin >> win[i];
	dp[100] = 0;
	FOR(i, 1, N) {
		FOR(j, 0, 100 - lose[i]) {
			if (dp[j + lose[i]] == -1) continue;
			dp[j] = max(dp[j], dp[j + lose[i]] + win[i]);
		}
	}
	int maxi = 0;
	FOR(i, 1, 100) {
		maxi = max(maxi, dp[i]);
	}
	cout << maxi;

	return 0;
}