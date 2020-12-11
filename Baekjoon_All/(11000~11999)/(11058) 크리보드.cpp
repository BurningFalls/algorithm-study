#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll dp[101];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 0, 5)
		dp[i] = i;
	FOR(i, 6, N) {
		dp[i] = max({ dp[i - 1] + 1, dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4 });
	}
	cout << dp[N];

	return 0;
}