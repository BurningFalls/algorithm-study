#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int P[1001];
int dp[1001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> P[i];
	dp[0] = 0;
	FOR(i, 1, N) {
		dp[i] = INF;
		FOR(j, 0, i) {
			dp[i] = min(dp[i], dp[j] + P[i - j]);
		}
	}
	cout << dp[N];

	return 0;
}