#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[1001];

int main() {
	FASTIO;
	FOR(i, 1, 1000) {
		dp[i] = 1;
	}
	FOR(i, 1, 1000) {
		FOR(j, 0, i - 1) {
			if ((i - j) % 2 == 1) continue;
			dp[i] += dp[(i - j) / 2];
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}


	return 0;
}