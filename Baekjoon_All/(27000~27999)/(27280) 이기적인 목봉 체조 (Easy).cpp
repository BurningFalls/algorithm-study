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
	vector<ll> H(N + 1), S(N + 1);
	vector<vector<ll>> sum(N + 1, vector<ll>(N + 1, 0));
	vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
	FOR(i, 1, N) {
		cin >> H[i] >> S[i];
	}

	FOR(i, 1, N) {
		ll max_num = 0;
		ll tmp = 0;
		FOR(j, i, N) {
			if (max_num < H[j]) {
				max_num = H[j];
				tmp = S[j];
			}
			else if (max_num == H[j]) {
				tmp += S[j];
			}
			sum[i][j] = tmp;
		}
	}

	FOR(i, 1, N) {
		dp[i][1] = sum[1][i];
	}
	FOR(i, 1, N) {
		FOR(j, 2, min(i, M)) {
			FOR(k, j - 1, i - 1) {
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + sum[k + 1][i]);
			}
		}
	}

	cout << dp[N][M];

	return 0;
}