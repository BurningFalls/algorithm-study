#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

struct NODE {
	int p;
	int q;
	int r;
	int s;
};

int dp[101][101][101][2];

int main() {
	FASTIO;
	FOR(i, 0, 100) {
		FOR(j, 0, 100) {
			FOR(k, 0, 100) {
				FOR(l, 0, 1) {
					dp[i][j][k][l] = -INF;
				}
			}
		}
	}
	int N, A, B;
	cin >> N;
	cin >> A >> B;
	vector<NODE> v(N + 1);
	FOR(i, 1, N) {
		cin >> v[i].p >> v[i].q >> v[i].r >> v[i].s;
	}
	dp[1][1][0][0] = max(v[1].p, v[1].q);
	dp[1][0][1][0] = v[1].s;
	dp[1][0][0][1] = v[1].r;
	FOR(i, 2, N) {
		FOR(j, 1, i) {
			FOR(k, 0, j) {
				if (j == k) {
					dp[i][k][j - k][0] = max(dp[i - 1][k - 1][j - k][0], dp[i - 1][k - 1][j - k][1]) + max(v[i].p, v[i].q);
				}
				else if (k == 0) {
					dp[i][k][j - k][0] = max(dp[i - 1][k][j - k - 1][0], dp[i - 1][k][j - k - 1][1]) + v[i].s;
				}
				else {
					int a = dp[i - 1][k - 1][j - k][0] + max(v[i].p, v[i].q);
					int b = dp[i - 1][k - 1][j - k][1] + max(v[i].p, v[i].q);
					int c = dp[i - 1][k][j - k - 1][0] + v[i].s;
					int d = dp[i - 1][k][j - k - 1][1] + v[i].s;
					dp[i][k][j - k][0] = max({ a, b, c, d });
				}
				dp[i][k][j - k][1] = dp[i - 1][k][j - k][0] + v[i].r;
			}
		}
	}

	int maxi = 0;
	FOR(i, 1, N) {
		FOR(j, 1, i) {
			FOR(k, 0, j) {
				FOR(l, 0, 1) {
					if (j - k > A) continue;
					if (k < B) continue;
					maxi = max(maxi, dp[i][k][j - k][l]);
				}
			}
		}
	}
	cout << maxi;


	return 0;
}