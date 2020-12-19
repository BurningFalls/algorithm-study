#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MOD 1000000000

ll dp[1000001];

int main() {
	FASTIO;
	FOR(i, 0, 1000000)
		dp[i] = 1;
	int N;
	cin >> N;
	for (int i = 2; i <= N; i *= 2) {
		FOR(j, i, N) {
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	cout << dp[N];

	return 0;
}