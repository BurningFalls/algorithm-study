#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dp[2001];
pii arr[21];

int main() {
	FASTIO;
	memset(dp, -1, sizeof(dp));
	int C, N;
	cin >> C >> N;
	FOR(i, 1, N) {
		int cost, customer;
		cin >> cost >> customer;
		arr[i] = { cost, customer };
	}
	sort(arr + 1, arr + N + 1);
	dp[0] = 0;
	FOR(i, 1, N) {
		FOR(j, 1, 2000) {
			int tmp = j - arr[i].second;
			if (tmp >= 0 && dp[tmp] != -1) {
				if (dp[j] == -1)
					dp[j] = dp[tmp] + arr[i].first;
				else
					dp[j] = min(dp[j], dp[tmp] + arr[i].first);
			}
		}
	}
	int minimum = 987654321;
	FOR(i, C, 2000) {
		if (dp[i] == -1) continue;
		minimum = min(minimum, dp[i]);
	}
	cout << minimum;

	return 0;
}