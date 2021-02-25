#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

pair<int, int> candy[5001];
int dp[10001];

int main() {
	FASTIO;
	int N;
	double M;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		memset(dp, 0, sizeof(dp));
		FOR(i, 1, N) {
			int C;
			double P;
			cin >> C >> P;
			candy[i] = { C, (int)(P * 100 + 0.5) };
		}
		int new_M = (int)(M * 100) + 0.5;
		FOR(i, 1, N) {
			FOR(j, candy[i].second, new_M) {
				dp[j] = max(dp[j], dp[j - candy[i].second] + candy[i].first);
			}
		}
		cout << dp[new_M] << "\n";
	}

	return 0;
}