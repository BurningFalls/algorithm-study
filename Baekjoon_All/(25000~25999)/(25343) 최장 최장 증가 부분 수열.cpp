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
	int N;
	cin >> N;
	vector<vector<int>> Map(N, vector<int>(N));
	vector<vector<int>> dp(N, vector<int>(N, 0));
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			cin >> Map[i][j];
		}
	}

	int ans = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N - 1) {
			int maxi = 0;
			FOR(y, 0, i) {
				FOR(x, 0, j) {
					if (Map[y][x] < Map[i][j]) {
						maxi = max(maxi, dp[y][x]);
					}
				}
			}
			dp[i][j] = maxi + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;

	return 0;
}