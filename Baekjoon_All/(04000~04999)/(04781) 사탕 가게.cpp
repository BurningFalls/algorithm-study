#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int C[5001];
int P[5001];
int dp[10001];

int main() {
	FASTIO;
	int N, M;
	double m;
	while (true) {
		MEMSET(dp, -1);
		cin >> N >> m;
		if (N == 0)
			break;
		M = int(m * 100 + 0.5);
		FOR(i, 1, N) {
			double p;
			cin >> C[i] >> p;
			P[i] = int(p * 100 + 0.5);
		}
		dp[0] = 0;
		FOR(i, 1, N) {
			FOR(j, P[i], M) {
				if (dp[j - P[i]] == -1) continue;
				dp[j] = max(dp[j], dp[j - P[i]] + C[i]);
			}
		}
		int maxi = 0;
		FOR(i, 0, M)
			maxi = max(maxi, dp[i]);
		cout << maxi << "\n";
	}

	return 0;
}