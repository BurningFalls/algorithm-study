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
#define MOD 1000000007

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<ll> dp(1516);
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	FOR(i, 3, 1515) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % MOD;
	}
	cout << dp[N];

	return 0;
}