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
	int N, K, X;
	cin >> N >> K >> X;
	vector<pii> v(N);
	int sum = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i].first >> v[i].second;
		sum += v[i].first;
	}
	vector<vector<int>> dp(sum + 1, vector<int>(K + 1, 0));
	dp[0][0] = 1;
	FOR(i, 0, N - 1) {
		ROF(j, K, 1) {
			ROF(k, sum, v[i].first) {
				dp[k][j] |= dp[k - v[i].first][j - 1];
			}
		}
	}

	int maxi = 0;
	FOR(i, 0, sum) {
		if (dp[i][K]) {
			maxi = max(maxi, i * (X * K - i));
		}
	}
	cout << maxi;

	return 0;
}