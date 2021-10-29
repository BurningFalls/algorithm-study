#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

ll dp[21][21][21];

int main() {
	FASTIO;
	dp[1][1][1] = 1;
	FOR(n, 2, 20) {
		FOR(l, 1, n) {
			FOR(r, 1, n) {
				dp[n][l][r] = dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + (dp[n - 1][l][r]) * (n - 2);
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int N, L, R;
		cin >> N >> L >> R;
		cout << dp[N][L][R] << "\n";
	}

	return 0;
}