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
	vector<vector<int>> dp(1001, vector<int>(1001, 0));
	FOR(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		dp[min(a, b)][max(a, b)] = 1;
	}

	FOR(i, 1, 1000) {
		FOR(j, i, 1000) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
		}
	}

	cout << dp[1000][1000];

	return 0;
}