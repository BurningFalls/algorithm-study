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
#define MOD 1000000000

ll dp[1000001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	dp[1] = 0;
	dp[2] = 1;
	FOR(i, 3, N) {
		dp[i] = ((dp[i - 2] + dp[i - 1]) * (i - 1)) % MOD;
	}
	cout << dp[N];


	return 0;
}