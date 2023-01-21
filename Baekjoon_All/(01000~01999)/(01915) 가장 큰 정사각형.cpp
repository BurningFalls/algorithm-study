#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<char>> Map(N + 1, vector<char>(M + 1));
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> Map[i][j];
		}
	}

	int maxi = 0;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (Map[i][j] == '0') continue;
			dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
			maxi = max(maxi, dp[i][j]);
		}
	}
	cout << maxi * maxi;

	return 0;
}