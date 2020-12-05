#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1500001

int T[MAX];
int P[MAX];
int dp[MAX] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> T[i] >> P[i];
	}
	ROF(i, N, 1) {
		if (i + T[i] > N + 1)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
	}
	cout << dp[1];

	return 0;
}