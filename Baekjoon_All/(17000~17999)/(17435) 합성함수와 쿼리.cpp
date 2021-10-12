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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int M;
	cin >> M;
	vector<vector<int>> dp(M + 1, vector<int>(21, 0));
	FOR(i, 1, M) {
		cin >> dp[i][0];
	}
	FOR(i, 1, 20) {
		FOR(j, 1, M) {
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
	int Q;
	cin >> Q;
	FOR(q, 1, Q) {
		int N, X;
		cin >> N >> X;
		ROF(i, 20, 0) {
			if (N & (1 << i)) {
				X = dp[X][i];
			}
		}
		P1(X);
	}


	return 0;
}