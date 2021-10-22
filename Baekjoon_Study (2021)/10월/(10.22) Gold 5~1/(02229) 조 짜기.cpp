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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> num(N);
	vector<int> dp(N, 0);
	FOR(i, 0, N - 1) {
		cin >> num[i];
	}
	FOR(i, 0, N - 1) {
		dp[i] = abs(num[0] - num[i]);
		FOR(j, 1, i) {
			dp[i] = max(dp[i], dp[j - 1] + abs(num[j] - num[i]));
		}
	}
	cout << dp[N - 1];


	return 0;
}